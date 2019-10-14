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
      <div class="List">
        <table border="1">
          ${trList.join('')}
        </table>
      </div>
    `)
  }
}

const natureShow = () => {
  let reflexivity, symmetry, transitivity, oppsiteReflexivity, oppsiteSymmetry;
  $('#list').click((e) => {
    $(e.target).prop("nodeName") == 'TD' ? zeroExchangeOne() : ''

    function zeroExchangeOne() {
      $(e.target).text($(e.target).text() == 0 ? 1 : 0)
    }
  })

  $('#natureShow').click(() => {
    let trList = [...$('tr')],
      arr = [];
    trList.map(item => {
      arr.push($(item).children())
    })

    reflexivity = Reflexivity(arr)
    symmetry = Symmetry(arr)
    transitivity = Transitivity(arr)
    oppsiteReflexivity = OppsiteReflexivity(arr)
    oppsiteSymmetry = OppsiteSymmetry(arr)

    $('.result').append(`
      <p>自反性：${reflexivity}</p>
      <p>反自反性：${oppsiteReflexivity}</p>
      <p>对称性：${symmetry}</p>
      <p>反对称性：${oppsiteSymmetry}</p>
      <p>传递性：${transitivity}</p>
    `)
  })

  function Reflexivity(arr) {
    let result = 'Yes';
    for (let l = 0; l < line; l++) {
      console.log(arr[l][l])
      if (arr[l][l].innerText == 0) {
        result = 'Not'
        break;
      }
    }
    return result;
  }

  function Symmetry(arr) {
    let result = 'Yes';
    if (line == 1) {
      result = 'Not';
      return result;
    }
    for (let l = 0; l < line; l++) {
      for (let c = 0; c < col; c++) {
        if (arr[c][l] && arr[l][c]) {
          if ((arr[l][c].innerText != arr[c][l].innerText) && arr[l][c].innerText == 0) {
            result = 'Not';
            break;
          }
        }
      }
    }
    return result;
  }

  function Transitivity(arr) {
    let result = 'Not', arr1;

    arr1 = [...document.querySelectorAll("td")].filter(function (ele) {
      return ele.innerText == 1
    })
    if (arr1.length == 1) {
      result = 'Yes';
      return result;
    }

    for (let l = 0; l < line; l++) {
      for (let c = 0; c < col - 1; c++) {
        for (let z = 0; z < col - 1; z++) {
          if (arr[c][l] && arr[l][c]) {
            if ((arr[l][c].innerText == arr[c][z].innerText) && (arr[l][c].innerText == arr[l][z].innerText) && arr[l][c].innerText == 1) {
              result = 'Yes';
              break;
            }
          }
        }
      }
    }
    return result;
  }

  function OppsiteReflexivity(arr) {
    let result = 'Yes';
    for (let l = 0; l < line; l++) {
      if (arr[l][l].innerText == 1) {
        result = 'Not'
        break;
      }
    }
    return result;
  }

  function OppsiteSymmetry(arr) {
    let result = 'Not';
    for (let l = 0; l < line; l++) {
      for (let c = 0; c < col - 1; c++) {
        if (arr[c][l] && arr[l][c]) {
          if ((arr[l][c].innerText == arr[c][l].innerText) && l == c && arr[l][c].innerText == 1) {
            result = 'Yes';
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