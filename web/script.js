Init = function(){
  List = document.getElementsByTagName("li")
  for (var i = List.length - 1; i >= 0; i--) {
    
    if(localStorage.getItem(List[i].id) === null)  localStorage.setItem(List[i].id, 0);
    // console.log(localStorage.getItem(List[i].id))
  }
  showCart()
}
/*
  function that handles all transactions
  namely addition of item, increaseing and decreasing quantity and deleting from cart
*/
transactionCart = function(id, type){
  // item = document.getElementById(id);
  q = parseInt(localStorage.getItem(id))
  if(type == 'addition'){
    // console.log("added")
    localStorage.setItem(id, q+1)
  }else if(type == 'subtraction'){
    localStorage.setItem(id, q-1)
  }else if(type == 'deletion')localStorage.setItem(id, 0)
  else console.log("err")
  // console.log(item.id+" "+item.getAttribute("name")+" "+item.getAttribute("price"))
  
  cartTable = document.getElementById("cart")
  rowCount = cartTable.rows.length
  for (var i = 1;i<rowCount-1;i++) {
    cartTable.deleteRow(1);
  }
  showCart()
}

/* 
  function to show cart item in table 
*/
showCart = function(){
  Sum = 0
  List = document.getElementsByTagName("li")
  cartTable = document.getElementById("cart")
  rowCount = 0
  if(cartTable)
  rowCount = cartTable.rows.length

  for (var i = 0; i <List.length; i++) {
    if(localStorage.getItem(List[i].id) > 0){
      quantity = localStorage.getItem(List[i].id)
      cartTable = document.getElementById("cart")
      row = cartTable.insertRow(rowCount-1)
      cell0 = row.insertCell(0)
      cell0.innerHTML = "<button  onclick='delItem("+List[i].id+")'>x</button>"+List[i].getAttribute("name")
      cell1 = row.insertCell(1)
      cell1.innerHTML = "<button  onclick='addItem("+List[i].id+")'>+</button>"+quantity+"<button onclick='minItem("+List[i].id+")' >-</button>"
      cell2 = row.insertCell(2)
      cell2.innerHTML = List[i].getAttribute("price")
      cell3 = row.insertCell(3)
      value = parseInt(List[i].getAttribute("price"))*parseInt(quantity)
      Sum += value
      cell3.innerHTML = value
    }
  }
  Total = document.getElementById("total_amount")
  if(Total)
  Total.innerHTML = "Rs. "+Sum
}

/* to add and item */
addItem = function(item){
  // console.log("add for "+item)
  transactionCart(item, 'addition')
}
/* to decrease quantity by one */
minItem = function(item){
  //console.log("min for "+item)
  transactionCart(item, 'subtraction')
}
/* to remove item form cart */
delItem = function(item){
  transactionCart(item, 'deletion')
}
/* to reset the local storage */
deleteLocalStorage = function(){
  localStorage.clear()
  location.reload()
}
