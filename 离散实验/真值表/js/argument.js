$('#goBtn').click(function () {
  let List = [],
    argumentList = [],
    conditions = [],
    tfList = [],
    resultList = [],
    MainDisjunctiveNormalForm,
    PrincipalConjunctiveNormalForm,
    a = [],
    finalArgument;

  getValue()
  argument()
  isError()

  function isError() {
    if ((!!finalArgument.indexOf('∧') || !!finalArgument.indexOf('→') || !!finalArgument.indexOf('⇔') || !!finalArgument.indexOf('∨'))) {
      truthTable()
      mainDisjunctiveNormalForm()
      principalConjunctiveNormalForm()
    } else {
      console.log("error")
      $('body').append(`
      <div class ="error">
        <p>检查一下表达式是不是写错了噢~！</p>
        <button id="close">好的好的，我马上乖乖写好（</button>
      </div>
      `)
      $('.error').css('opacity', '0')
      setTimeout(() => {
        $('.error').css('opacity', '1')
      }, 300)
    }

    $('#close').click(function () {
      $('.error').css('opacity', '0')
      setTimeout(() => {
        $('.error').remove()
      }, 300)

    })
  }

  function getValue() {
    let list = [...$('.ui-draggable')];
    list.sort(function (a, b) {
      return $(a).offset().left - $(b).offset().left
    }).map(item => {
      List.push(item.innerText)
    })
    finalArgument = List.join('')
  }

  function SingleCondition() {
    typeof List == 'string' ?
      List = List.split('→') :
      List = List.join('').split('→')
    List = `┐(${List[0]})∨(${List[1]})`.split('')
    andOrNot()
  }

  function andOrNot() {
    List = List.join('').replace(/┐/g, '!').replace(/∧/g, '&&').replace(/∨/g, '||').replace(/→/g, '∨')
  }

  function DoubleConditions() {
    List.join('').split('→').join(',').split(',').map(item => {
      a.push(item)
    })
    a[0] = a[0].replace(/⇔/, '^').split('')
    a[0].splice(0, 0, '!')
    a[0] = a[0].join('')

    List = [...a].join('→')

    List.indexOf('→') ?
      SingleCondition() :
      andOrNot()
  }

  function argument() {
    List.join('').indexOf('⇔') >= 0 ?
      DoubleConditions() :
      List.join('').indexOf('→') >= 0 ?
      SingleCondition() :
      andOrNot()
    List = List.split('')
  }

  function createTruthTable() {
    let thTemplateList = [],
      trList = [],
      tdList = [];

    argumentList.map(item => {
      thTemplateList.push(`<th>${item}</th>`)
      tdList.push(`<td></td>`)
    })

    for (let i = 0; i <= parseInt(tfList, 2); i++) {
      trList.push(`<tr class="TruthFalse">${tdList.join('')}</tr>`)
    }

    $('.truthTable').append(`
      <table border="1">
        <tr>${thTemplateList.join('')}</tr>
          ${trList.join('')}
      </table>
    `)
  }

  function conditionalCombination() {
    List.map(item => {
      item.match('[A-Z]') ? argumentList.push(item) : ''
    })

    argumentList = [...new Set(argumentList)];

    tfList = new Array(argumentList.length).fill(1).join('');

    for (let i = 0; i <= parseInt(tfList, 2); i++) {
      let item = i.toString(2).padStart(argumentList.length, '0')
      conditions.push(item)
    }

    argumentList.push(List.join(''))
    conditions = conditions.join('').replace(/0/g, 'F').replace(/1/g, 'T').split('')
  }

  function fillTruthTable() {
    $(".TruthFalse").find("td:last-of-type").addClass("result");

    $(".TruthFalse").find("td:not(.result)").each((index, cur) => {
      cur.innerText = conditions[index]
    })

    for (let i = 0; i < conditions.length; i + argumentList.length - 1) {
      resultList.push(conditions.splice(i, i + argumentList.length - 1))
    }

    let finalResult = [];
    for (let k = 0; k <= parseInt(tfList, 2); k++) {
      let arr = [...List];
      for (let j = 0; j < List.length; j++) {
        for (let i = 0; i < argumentList.length - 1; i++) {
          if (List[j] == argumentList[i])
            arr[j] = resultList[k][i]
        }
      }
      finalResult.push(eval(arr.join('').replace(/F/g, 'false').replace(/T/g, 'true')))
    }

    $('.result').each((index, cur) => {
      cur.innerText = finalResult[index]
    })
    // finalArgument = '((┐┐┐P∨Q)⇔(A∧B))→(R∨(┐B∧C))'
    $(".truthTable table").find("th:last-of-type")[0].innerText = finalArgument
  }

  function truthTable() {
    conditionalCombination()
    createTruthTable()
    fillTruthTable()
    $('.container').css('transform', 'translateY(100vh)')
    $('.truthTableBox').css('transform', 'translateY(-98vh)')

    if ($('.truthTable').height() > '450')
      $('.truthTable').css('overflowY', 'scroll').css('overflowX', 'hidden')
  }

  function mainDisjunctiveNormalForm() {
    let mainDisjunctiveNormalFormList = [],
      mainDisjunctiveNormalForm = [];

    $('.result').each((index, cur) => {
      if (cur.innerText == 'true') {
        for (let i = 0; i < resultList[index].length; i++) {
          resultList[index][i] == 'T' ?
            mainDisjunctiveNormalFormList.push(argumentList[i]) :
            mainDisjunctiveNormalFormList.push(`┐${argumentList[i]}`)
        }
      }
    })

    for (let i = 0; i < mainDisjunctiveNormalFormList.length; i + argumentList.length - 1) {
      mainDisjunctiveNormalForm.push(mainDisjunctiveNormalFormList.splice(i, i + argumentList.length - 1))
    }

    mainDisjunctiveNormalForm.map(item => {
      item[0] = `(${item[0]}`
      item[item.length - 1] = `${item[item.length-1]})∨`
    })
    MainDisjunctiveNormalForm = mainDisjunctiveNormalForm.join('').replace(/,/g, '∧')
    MainDisjunctiveNormalForm = MainDisjunctiveNormalForm.substring(0, MainDisjunctiveNormalForm.length - 1)

    $('#MainDisjunctiveNormalForm').text(`${MainDisjunctiveNormalForm}`)

  }

  function principalConjunctiveNormalForm() {
    let principalConjunctiveNormalFormList = [],
      principalConjunctiveNormalForm = [];

    $('.result').each((index, cur) => {
      if (cur.innerText == 'false') {
        for (let i = 0; i < resultList[index].length; i++) {
          resultList[index][i] == 'F' ?
            principalConjunctiveNormalFormList.push(argumentList[i]) :
            principalConjunctiveNormalFormList.push(`┐${argumentList[i]}`)
        }
      }
    })

    for (let i = 0; i < principalConjunctiveNormalFormList.length; i + argumentList.length - 1) {
      principalConjunctiveNormalForm.push(principalConjunctiveNormalFormList.splice(i, i + argumentList.length - 1))
    }

    principalConjunctiveNormalForm.map(item => {
      item[0] = `(${item[0]}`
      item[item.length - 1] = `${item[item.length-1]})∧`
    })
    PrincipalConjunctiveNormalForm = principalConjunctiveNormalForm.join('').replace(/,/g, '∨')
    PrincipalConjunctiveNormalForm = PrincipalConjunctiveNormalForm.substring(0, PrincipalConjunctiveNormalForm.length - 1)
    $('#PrincipalConjunctiveNormalForm').text(`${PrincipalConjunctiveNormalForm}`)

  }

})