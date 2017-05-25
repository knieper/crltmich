$(document).ready(function(){
  $(".toggler").click(function(){
    $(this).next().slideToggle("slow");
    return false;
  }).next().hide();
});
