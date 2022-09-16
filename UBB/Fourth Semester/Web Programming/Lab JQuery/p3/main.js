const selectors = {
  boardContainer: document.querySelector(".board-container"),
  board: document.querySelector(".board"),
  moves: document.querySelector(".moves"),
  timer: document.querySelector(".timer"),
  start: document.querySelector("button"),
  win: document.querySelector(".win"),
};

const state = {
  gameStarted: false,
  flippedCards: 0,
  totalFlips: 0,
  totalTime: 0,
  loop: null,
  person_nickname: "",
};

const shuffle = (array) => {
  const clonedArray = [...array];

  for (let index = clonedArray.length - 1; index > 0; index--) {
    const randomIndex = Math.floor(Math.random() * (index + 1));
    const original = clonedArray[index];

    clonedArray[index] = clonedArray[randomIndex];
    clonedArray[randomIndex] = original;
  }

  return clonedArray;
};

const pickRandom = (array, items) => {
  const clonedArray = [...array];
  const randomPicks = [];

  for (let index = 0; index < items; index++) {
    const randomIndex = Math.floor(Math.random() * clonedArray.length);

    randomPicks.push(clonedArray[randomIndex]);
    clonedArray.splice(randomIndex, 1);
  }

  return randomPicks;
};

const generateGame = () => {
  const dimensions = selectors.board.getAttribute("data-dimension");

  if (dimensions % 2 !== 0) {
    throw new Error("The dimension of the board must be an even number.");
  }

  const emojis = ["🐀", "🐂", "🐅", "🐇", "🐊", "🐎", "🐒", "🐓", "🐖", "🐩"];
  const picks = pickRandom(emojis, (dimensions * dimensions) / 2);
  const items = shuffle([...picks, ...picks]);
  const cards = `
        <div class="board" style="grid-template-columns: repeat(${dimensions}, auto)">
            ${items
              .map(
                (item) => `
                <div class="card">
                    <div class="card-front"></div>
                    <div class="card-back">${item}</div>
                </div>
            `
              )
              .join("")}
       </div>
    `;

  const parser = new DOMParser().parseFromString(cards, "text/html");

  selectors.board.replaceWith(parser.querySelector(".board"));
};

const startGame = () => {
  state.gameStarted = true;
  selectors.start.classList.add("disabled");

  state.loop = setInterval(() => {
    state.totalTime++;

    selectors.moves.innerText = `${state.totalFlips} moves`;
    selectors.timer.innerText = `time: ${state.totalTime} sec`;
  }, 1000);
};

const flipBackCards = () => {
  document.querySelectorAll(".card:not(.matched)").forEach((card) => {
    card.classList.remove("flipped");
  });

  state.flippedCards = 0;
};

const flipCard = (card) => {
  state.flippedCards++;
  state.totalFlips++;

  if (!state.gameStarted) {
    startGame();
  }

  if (state.flippedCards <= 2) {
    card.classList.add("flipped");
  }

  if (state.flippedCards === 2) {
    const flippedCards = document.querySelectorAll(".flipped:not(.matched)");

    if (flippedCards[0].innerText === flippedCards[1].innerText) {
      flippedCards[0].classList.add("matched");
      flippedCards[1].classList.add("matched");
    }

    setTimeout(() => {
      flipBackCards();
    }, 1000);
  }

  // If there are no more cards that we can flip, we won the game
  if (!document.querySelectorAll(".card:not(.flipped)").length) {
    setTimeout(() => {
      selectors.boardContainer.classList.add("flipped");
      selectors.win.innerHTML = `
                <span class="win-text">
                    You won!<br />
                    with <span class="highlight">${state.totalFlips}</span> moves<br />
                    under <span class="highlight">${state.totalTime}</span> seconds <br />
                    </br>
                    <button onclick="restart()">Restart</button>
                </span>
            `;
      clearInterval(state.loop);
      post_score(state.person_nickname, state.totalTime);
    }, 1000);
  }
};

const attachEventListeners = () => {
  document.addEventListener("click", (event) => {
    const eventTarget = event.target;
    const eventParent = eventTarget.parentElement;

    if (
      eventTarget.className.includes("card") &&
      !eventParent.className.includes("flipped")
    ) {
      flipCard(eventParent);
    } else if (
      eventTarget.nodeName === "BUTTON" &&
      !eventTarget.className.includes("disabled")
    ) {
      getNickname();
      startGame();
    }
  });
};

function restart() {
  location.reload();
  generateGame();
  attachEventListeners();
}

function get_highscores() {
  var request, response, select;

  request = new XMLHttpRequest();
  request.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      response = this.responseText;
      let n = 4;
      response = response.split("*");
      if (response.length < 3) n = response.length;
      let str = `<table id = "high_scores">
      <tr>
       <th  colspan="2" halign="center"><h3 text-align = "center">HighScores</h3></th>
     </tr>
      <tr>
     <td halign="center"><h4 text-align = "center">Nickname</h4></td>
     <td halign="center"><h4 text-align = "center">HighScore</h4></td>
     </tr>`;

      for (i = 0; i < n - 1; i += 1) {
        str = str + response[i];
      }
      str = str + `</table>`;
      document.getElementById("scores").innerHTML = str;
    }
  };
  request.open("GET", "http://localhost/web/get_for_memory_game.php", true);
  request.send("");
}

function getNickname() {
  var txt;
  state.person_nickname = document.getElementById("text_nickname").value;
  if (nickname == null || nickname === "") {
    alert("Invalid nickname");
  }
}

get_highscores();
generateGame();
attachEventListeners();

function post_score(name, score) {
  var request;
  request = new XMLHttpRequest();
  request.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      alert("Saved to database!");
    }
  };
  request.open("POST", "http://localhost/web/post_for_memory_game.php", true);
  request.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  request.send("nickname=" + name + "&score=" + score);
}
