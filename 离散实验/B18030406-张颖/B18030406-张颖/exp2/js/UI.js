const getLineColBox_Up = ()=>{
  $('#create').click(()=>{
    $('.getLineCol').css('transform','translateY(-100vh)')
    $('#list').css('transform','translateY(0)').css('top','0');
  })
  $('#natureShow').click(()=>{
    $('#ShowBtn').css('animation','Btn_scale 1s 1 forwards')
    $('.result').css('transform','translateY(0)').css('bottom','10%');
  })
}

getLineColBox_Up()