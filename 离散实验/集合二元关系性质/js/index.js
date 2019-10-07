let line, col, matrix = [];

const create = () => {

  $('#create').click(() => {
    line = parseInt($('#line').val())
    col = parseInt($('#col').val())

    matrix = [...Matrix(line, col)]
    createList()
  })

  function Matrix(line, col) {
    let result = []
    for (let i = 0; i < line; i++) {
      result.push(new Array(col).fill(0))
    }
    return result;
  }

  function createList() {
    let trList = [],
      tdList = [];

    for (let i = 0; i < col; i++) {
      tdList.push(`<td>0</td>`)
    }

    for (let i = 0; i < line; i++) {
      trList.push(`<tr>${tdList.join('')}</tr>`)
    }

    $('#list').append(`
    <table border="1">
        ${trList.join('')}
    </table>
    `)
  }
}

const natureShow = () => {
  let reflexivity ,symmetry, transitivity;
  $('#list').click((e) => {
    $(e.target).prop("nodeName") == 'TD' ? zeroExchangeOne() : ''

    function zeroExchangeOne() {
      $(e.target).text($(e.target).text() == 0 ? 1 : 0)
    }
  })

  $('#natureShow').click(() => {
    let tdList = [...$('td')], arr = [];

    for (let i = 0; i < tdList.length; i + line - 1) {
      arr.push(tdList.splice(i, i + line))
    }

    reflexivity = Reflexivity(arr)
    symmetry = Symmetry(arr)
    transitivity = Transitivity(arr)
  })

  function Reflexivity(arr) {
    let result = 'Yes';
    for (let l = 0; l < line; l++) {
      for (let c = 0; c < col; c++) {
        if (arr[l][l].innerText == 0)
          result = 'Not'
      }
    }
    return result;
  }

  function Symmetry(arr){
    let result = 'Not';
    for (let l = 0; l < line; l++) {
      for (let c = 0; c < col -1; c++) {
        if ((arr[l][c].innerText == arr[c][l].innerText) && arr[l][c].innerText == 1){
          result = 'Yes';
          break;
        }
      }
    }
    return result;
  }

  function Transitivity(arr){
    let result = 'Yes';
    for (let l = 0; l < line; l++) {
      for (let c = 0; c < col - 1; c++) {
        for(let z = 0;z < col -1; z++){
          if ((arr[l][c].innerText == arr[c][z].innerText) && (arr[l][c].innerText == arr[l][z].innerText) && arr[l][c].innerText == 1){
            result = 'Not';
            break;
        }
        }
      }
    }
    return result;
  }
}

create()
natureShow()