$('#goBtn').click(function () {
  let List = [],
      originalArgument = [],
      argumentList = [],
      conditions = [],
      tfList = [],
      resultList = [],
      MainDisjunctiveNormalForm,
      PrincipalConjunctiveNormalForm,
      finalArgument;

  getValue()
  argument()
  truthTable()
  mainDisjunctiveNormalForm()
  principalConjunctiveNormalForm()

  function getValue() {
    let list = [...$('.ui-draggable')];
    list.sort(function (a, b) {
      return $(a).offset().left - $(b).offset().left
    }).map(item => {
      List.push(item.innerText)
    })
    originalArgument = [...List]
    finalArgument = originalArgument.join('')
  }

  function SingleCondition() {
    let indexList = [];
    originalArgument = [...List];
    originalArgument.map((item, index) => {
      item == '(' ? indexList.push(index) : ''
      if (item == '→' && List[index - 1] == ')') {
        List.splice(`${indexList[0]}`, 0, '┐')
      } else if (item == '→' && List[index - 1] !== ')') {
        index == 1 ?
          List.splice(0, 0, '┐') :
          List.splice(`${index-2}`, 0, '┐')
      }
    })
    List = List.join('').replace(/→/g, '∨').split('')
    andOrNot()
  }

  function andOrNot() {
    List = List.join('').replace(/┐/g, '!').replace(/∧/g, '&&').replace(/∨/g, '||').replace(/→/g, '∨').replace(/<=>/g, '&&')
  }

  function DoubleConditions() {
    List = List.join('').split('(').join('').split(')').join('').replace('<=>', ',').split(',')
    List = `((${List[0]})→(${List[1]}))→((${List[1]})→(${List[0]}))`.split('')
    List.find(function (ele) {
      return ele == '→'
    }) ? SingleCondition() : ''
    List = List.split('')
    andOrNot()
  }

  function argument() {
    List.find(function (ele) {
        return ele == '<=>'
      }) ? DoubleConditions() :
      List.find(function (ele) {
        return ele == '→'
      }) ? SingleCondition() :
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


    for(let i = 0; i <= parseInt(tfList,2); i++)
    {
      trList.push(`<tr class="TruthFalse">${tdList}</tr>`)
    }


    $('.truthTable').append(`
      <table border="1">
        <tr>${thTemplateList}</tr>
          ${trList}
      </table>
    `)
  }

  function conditionalCombination(){
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

  function fillTruthTable(){
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
    $(".truthTable table").find("th:last-of-type")[0].innerText = finalArgument
  }
  
  function truthTable() { 
    conditionalCombination()
    createTruthTable()
    fillTruthTable()
  }

  function mainDisjunctiveNormalForm(){
    let mainDisjunctiveNormalFormList = [],
        mainDisjunctiveNormalForm = [];

    $('.result').each((index, cur) => {
      if(cur.innerText == 'true'){
        for(let i = 0;i< resultList[index].length; i++){
          resultList[index][i] == 'T'? 
          mainDisjunctiveNormalFormList.push(argumentList[i])
          :
          mainDisjunctiveNormalFormList.push(`┐${argumentList[i]}`)
        }
      }
    })

    for(let i = 0;i< mainDisjunctiveNormalFormList.length;i + argumentList.length - 1){
      mainDisjunctiveNormalForm.push(mainDisjunctiveNormalFormList.splice(i, i + argumentList.length - 1))
    }

    mainDisjunctiveNormalForm.map(item =>{
      item[0] = `(${item[0]}`
      item[item.length-1] = `${item[item.length-1]})∨`
    })
    MainDisjunctiveNormalForm = mainDisjunctiveNormalForm.join('').replace(/,/g,'∧')
    MainDisjunctiveNormalForm = MainDisjunctiveNormalForm.substring(0,MainDisjunctiveNormalForm.length - 1)
    console.log(MainDisjunctiveNormalForm)
  }

  function principalConjunctiveNormalForm(){
    let principalConjunctiveNormalFormList = [],
        principalConjunctiveNormalForm = [];

    $('.result').each((index, cur) => {
      if(cur.innerText == 'false'){
        for(let i = 0;i< resultList[index].length; i++){
          resultList[index][i] == 'F'? 
          principalConjunctiveNormalFormList.push(argumentList[i])
          :
          principalConjunctiveNormalFormList.push(`┐${argumentList[i]}`)
        }
      }
    })

    for(let i = 0;i< principalConjunctiveNormalFormList.length;i + argumentList.length - 1){
      principalConjunctiveNormalForm.push(principalConjunctiveNormalFormList.splice(i, i + argumentList.length - 1))
    }

    principalConjunctiveNormalForm.map(item =>{
      item[0] = `(${item[0]}`
      item[item.length-1] = `${item[item.length-1]})∧`
    })
    PrincipalConjunctiveNormalForm = principalConjunctiveNormalForm.join('').replace(/,/g,'∨')
    PrincipalConjunctiveNormalForm = PrincipalConjunctiveNormalForm.substring(0,PrincipalConjunctiveNormalForm.length - 1)
    console.log(PrincipalConjunctiveNormalForm)
  }

})