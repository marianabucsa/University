function addEventsOnHeaders(sortBySelectedHeader) {
    let tables = document.getElementsByTagName("table");

    //functions
    function addEventToEachTable() {
        for (let i = 0; i < tables.length; ++i) {
            addEventToEachHeaderFromTable(tables[i]);
        }
    }

    function addEventToEachHeaderFromTable(table) {
        let headers = table.getElementsByTagName("th");
        let previousIndexSelectedHeader = null;

        for (let i = 0; i < headers.length; ++i) {
            headers[i].style.cursor = "pointer";
            let sortingAscending = true;
            headers[i].onclick = function () {
                if (previousIndexSelectedHeader === i)
                    sortingAscending = !sortingAscending;
                else
                    sortingAscending = true;
                console.log(this);
                previousIndexSelectedHeader = i;
                sortBySelectedHeader(i, sortingAscending, table);
            }
        }
    }

    addEventToEachTable();
}