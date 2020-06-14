Array.from(document.querySelectorAll("input")).forEach(function (select) {
  if (select.value == 20) select.checked = true;
});
[...document.querySelectorAll("textarea")].map(textarea => textarea.value ="很好");