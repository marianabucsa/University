$(document).ready(function () {

  $('#nume').on('input', function () {
    var input = $(this);
    var is_name = input.val();
    if (is_name) {
      input.removeClass("invalid").addClass("valid");
    } else {
      input.removeClass("valid").addClass("invalid");
    }
  });

  $('#data').on('input', function () {
    var input = $(this);
    var is_date = Date.parse(input.val());
    if (!isNaN(is_date)) {
      input.removeClass("invalid").addClass("valid");
    } else {
      input.removeClass("valid").addClass("invalid");
    }
  });

  $('#varsta').on('input', function () {
    var input = $(this);
    var is_integer = parseInt(input.val());
    if (!isNaN(is_integer)) {
      input.removeClass("invalid").addClass("valid");
    } else {
      input.removeClass("valid").addClass("invalid");
    }
  });


  $('#email').on('input', function () {
    var input = $(this);
    var re = /^[a-zA-Z0-9._]+@[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*$/;
    var is_email = re.test(input.val());
    if (is_email) {
      input.removeClass("invalid").addClass("valid");
    } else {
      input.removeClass("valid").addClass("invalid");
    }
  });


  $("form").submit(function (event) {

    var form_data = $(this).serializeArray();
    var error_free = true;

    $.each(form_data, function (i, field) {
      var element = $('#' + field.name);
      var valid = element.hasClass("valid");
      var error_element = $("#span" + field.name);
      if (!valid) {
        error_element.removeClass("error").addClass("error_show");
        error_free = false;
      } else {
        error_element.removeClass("error_show").addClass("error");
      }

      $("#results").append(field.name + ":" + field.value + " ");
    });

    if (!error_free) {
      event.preventDefault();
    } else {
      alert('No errors: Form will be submitted');
    }
  });
});
