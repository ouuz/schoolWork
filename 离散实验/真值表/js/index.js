$(function () {
  $('.argumentBall').click(function () {
    let move = $(`
      <div  class="argumentBall"
            style="position:absolute;
            top:${$(this).position().top}px;
            left:${$(this).position().left}px" 
      >
      ${$(this).text()}
      </div>
    `)
    $('.argument').append(move)
    move.draggable();
  })



  $('.connectorSquare').click(function () {
    let move = $(`
    <div  class="connectorSquare"
          style="position:absolute;
          top:${$(this).position().top}px;
          right:${$(this).position().left}px" 
    >
    ${$(this).text()}
    </div>
  `)
    $('.connectors').append(move)
    move.draggable();
  })


  $('#showBtn').click(function () {
    if ($(this).text() == '收起') {
      $('.a').css('opacity', '0').css('transform', 'translateX(20px)')
      $(this).text('展开')
    } else {
      $('.a').css('opacity', '1').css('transform', 'translateX(0)')
      $(this).text('收起')
    }
  })
});