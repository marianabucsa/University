var array = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9];
/*var array = [];
array[0].src = "ananas.jpg"; array[1].src = "ananas.jpg";
array[2].src = "capsune.jpg"; array[3].src = "capsune.jpg";
array[4].src = "cirese.jpg"; array[5].src = "cirese.jpg";
array[6].src = "mandarina.jpg"; array[7].src = "mandarina.jpg";
array[8].src = "mar.jpg"; array[9].src = "mar.jpg";
array[10].src = "mure.jpg"; array[11].src = "mure.jpg";
array[12].src = "para.jpg"; array[13].src = "para.jpg";
array[14].src = "piersica.jpg"; array[15].src = "piersica.jpg";
array[16].src = "zmeura.jpg"; array[17].src = "zmeura.jpg";*/
var values = [];
var tile_ids = [];
var tiles_flipped = 0;

function shuffle(arr) {
    var counter = array.length, temp, index;
    while (counter > 0) {
        index = Math.floor(Math.random() * counter);
        counter--;
        temp = array[counter];
        array[counter] = array[index];
        array[index] = temp;
    }
    return array;
}


function newBoard() {
    tiles_found = 0;
    var output = '';
    shuffle(array);
    for (var i = 0; i < array.length; i++) {
        output += '<div id="tile_' + i + '" onclick="flip(this,\'' + array[i] + '\')"></div>';
    }
    document.getElementById("memory_board").innerHTML = output;
}

function flip(tile, value) {
    if (tile.innerHTML == "" && values.length < 2) {
        tile.style.background = '#FFF';
        tile.innerHTML = value;
        if (values.length == 0) {
            values.push(value);
            tile_ids.push(tile.id);
        } else if (value.length == 1) {
            values.push(value)
            tile_ids.push(tile.id);
            if (values[0] == values[1]) {
                tiles_flipped_ = 2;
                values = [];
                tile_ids = [];
                if (tiles_flipped == array.length) {
                    alert("Board cleared... generating new board");
                    document.getElementById("memory_board").innerHTML = "";
                    newBoard();
                }
            } else {
                function flipBack() {
                    var tile1 = document.getElementById(tile_ids[0]);
                    var tile2 = document.getElementById(tile_ids[1]);
                    tile1.style.background = "darkblue";
                    tile2.style.background = "darkblue";
                    tile1.innerHTML = "";
                    tile2.innerHTML = "";
                    values = [];
                    tile_ids = [];
                }

                setTimeout(flipBack, 700);
            }
        }
    }
}
