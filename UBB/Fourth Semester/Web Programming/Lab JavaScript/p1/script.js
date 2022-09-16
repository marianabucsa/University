function move(idsource, iddest) {
    var source = document.getElementById(idsource);
    var selectedItem = source.selectedIndex;

    var dest = document.getElementById(iddest);
    var item = source[selectedItem].cloneNode(true);
    source.removeChild(source[selectedItem]);
    dest.appendChild(item);
}