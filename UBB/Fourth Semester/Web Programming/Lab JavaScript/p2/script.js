function verifyData() {
    var err = "";
    var nume = document.getElementById("nume").value.toString();
    console.log(nume);
    var data = document.getElementById("data").value.toString();
    console.log(data);
    var varsta = document.getElementById("varsta").value.toString();
    console.log(varsta);
    var email = document.getElementById("email").value.toString();
    console.log(email);
    //window.alert(nume + " " + data + " " + varsta);
    if (nume.localeCompare("") == 0) {
        err += "Nume invalid!\n";
        document.getElementById("nume").style.borderColor = "red";
    }
    else {
        document.getElementById("nume").style.borderColor = "black";
    }
    if (data.localeCompare("") == 0) {
        err += "Data invalida\n";
        document.getElementById("data").style.borderColor = "red";
    } else {
        d = Date.parse(data);
        if (isNaN(d)) {
            err += 'Data invalida!\n';
            document.getElementById("data").style.borderColor = "red";
        }
        else {
            document.getElementById("data").style.borderColor = "black";
        }
    }
    if (isNaN(parseInt(varsta)) || varsta.localeCompare("") == 0) {
        err += "Varsta invalida!\n";
        document.getElementById("varsta").style.borderColor = "red";
    }
    else {
        document.getElementById("varsta").style.borderColor = "black";
    }
    if (email.localeCompare("") == 0) {
        err += "Email invalid!\n";
        document.getElementById("email").style.borderColor = "red";
    }
    else {
        document.getElementById("email").style.borderColor = "black";
    }
    if (err.localeCompare("") != 0) {
        window.alert(err);
        return false;
    } else {
        window.alert("Datele sunt completate corect");
        document.getElementById("nume").clear();
        document.getElementById("data").clear();
        document.getElementById("varsta").clear();
        document.getElementById("email").clear();
        document.getElementById("nume").style.borderColor = "black";
        document.getElementById("data").style.borderColor = "black";
        document.getElementById("varsta").style.borderColor = "black";
        document.getElementById("email").style.borderColor = "black";
        //window.alert("Datele sunt completate corect");
    }
    //return false;
}