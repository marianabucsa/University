var slideIndex = 0, time = 3000;
showSlides();
var timer = setTimeout(showSlides, time);


function plusSlides(n) {
    slideIndex += n - 1;
    showSlides();
    clearTimeout(timer);
    timer = setTimeout(showSlides, time);
}

function showSlides() {
    var i;
    var slides = document.getElementsByClassName("mySlides");
    var dots = document.getElementsByClassName("dot");
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }
    if (slideIndex == -1) {
        slideIndex = slides.length - 1;
    }
    slideIndex++;
    if (slideIndex > slides.length) {
        slideIndex = 1
    }
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active", "");
    }
    slides[slideIndex - 1].style.display = "block";
    dots[slideIndex - 1].className += " active";
    clearTimeout(timer);
    timer = setTimeout(showSlides, time);
}