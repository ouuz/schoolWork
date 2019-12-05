$(function () {
    $('.argumentBall').click(function () {
      let move = $(`
        <div  class="argumentBall"
              style="position:absolute;
              top:${$(this).position().top}px;
              left:${$(this).position().left}px;
              color:#ffffff" 
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
              right:${$(this).position().left20}px;
              color:#ffffff" 
        >
          ${$(this).text()}
        </div>
      `)
      $('.connectors').append(move)
      move.draggable();
    })

  $('#showABtn').click(function () {
    if ($(this).text() == '收起') {
      $('.a').css('opacity', '0').css('transform', 'translateX(20px)')
      $(this).text('展开')
    } else {
      $('.a').css('opacity', '1').css('transform', 'translateX(0)')
      $(this).text('收起')
    }
  })

  $('#showBBtn').click(function () {
    if ($(this).text() == '收起') {
      $('.b').css('opacity', '0').css('transform', 'translateX(20px)')
      $(this).text('展开')
    } else {
      $('.b').css('opacity', '1').css('transform', 'translateX(0)')
      $(this).text('收起')
    }
  })

  $('#back').click(function () {
    $('.container').css('transform', 'translateY(0)')
    $('.truthTableBox').css('transform', 'translateY(0)')
    setTimeout(() => {
      window.location.reload()
    }, 500)
  })

  $('.Tips').click(function(){
    $('.Tips').offset().top > -200 ?
      $('.Tips').css('transform','translateY(0)').css('animation','shake 1s infinite')
      :
      $('.Tips').css('transform','translateY(60vh)').css('animation','shake 1s 0')
    
  })

  $(document).bind("selectstart",function(){return false;});
  

});