let filterarray=[];
let gallaryarray=[
    {
        "id" : "img1",
        "name" : "green shirt",
        "src" : "./images/t-shirt/t-shirt1.jfif",
        "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
        "price" : 500,
        "category" : "t-shirts"
    },
    {
      "id" : "img2",
      "name" : "black shirt",
      "src" : "./images/t-shirt/t-shirt2.jfif",
      "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
      "price" : 500,
      "category" : "t-shirts"
  },
  {
    "id" : "img3",
    "name" : "white shirt",
    "src" : "./images/t-shirt/t-shirt3.jfif",
    "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
    "price" : 500,
    "category" : "t-shirts"
},
{
  "id" : "img4",
  "name" : "yellow shirt",
  "src" : "./images/t-shirt/t-shirt4.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "t-shirts"
},
{
  "id" : "img5",
  "name" : "blue shirt",
  "src" : "./images/t-shirt/t-shirt5.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "t-shirts"
},
{
  "id" : "elec1",
  "name" : "headphone",
  "src" : "./images/electronics/item1.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "electronics"
},
{
  "id" : "elec2",
  "name" : "speaker",
  "src" : "./images/electronics/item2.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "electronics"
},
{
  "id" : "elec3",
  "name" : "projector",
  "src" : "./images/electronics/item3.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "electronics"
},
{
  "id" : "elec4",
  "name" : "labtop",
  "src" : "./images/electronics/item4.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "electronics"
},
{
  "id" : "elec5",
  "name" : "printer",
  "src" : "./images/electronics/item5.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "electronics"
},
{
  "id" : "acc1",
  "name" : "gold bracelet",
  "src" : "./images/accessories/acc1.png",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "accessories"
},
{
  "id" : "acc2",
  "name" : "white bracelet",
  "src" : "./images/accessories/acc2.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "accessories"
},
{
  "id" : "acc3",
  "name" : "gold ring",
  "src" : "./images/accessories/acc3.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "accessories"
},
{
  "id" : "acc4",
  "name" : "white ring",
  "src" : "./images/accessories/acc4.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "accessories"
},
{
  "id" : "acc5",
  "name" : "silver chain",
  "src" : "./images/accessories/acc5.jfif",
  "desc" : "Lorem ipsum dolor, sit amet consectetur adipisicing elit.",
  "price" : 500,
  "category" : "accessories"
}
]


showgallary(gallaryarray);

function showgallary(currarray)
{

  products=currarray

  document.getElementById("card").innerText="";
  for(var i=0;i<currarray.length;i++)
  {
    document.getElementById("card").innerHTML +=
    `<div class="col-md-4 mt-3">
      <div class="card p-3 ps-5 pe-5">
       <h4 class="text-capitalize text-center">${currarray[i].name}</h4>
       <img src="${currarray[i].src}" width="100%" height="320px"/>
       <p class="mt-2">${currarray[i].desc}</p>
       <p class="mt-2">${currarray[i].price} $</p>
       <button onclick='addToCart("${currarray[i].id}", this)' class="btn btn-primary w-100 mx-auto">Add to Cart</button>
      </div>
     </div>
    `
  }
}



// Search in gallerey 

document.getElementById("myinput").addEventListener("keyup",function()
{
  let text=document.getElementById("myinput").value;

  filterarray = gallaryarray.filter(function(a)
  {
    if(a.name.includes(text))
    {
      return a.name;
    }
    if(a.category.includes(text))
      {
        return a.category;
      }


  });
  if(this.value=="")
  {
    showgallary(gallaryarray);
  }
  else{
    if(filterarray==""){
      document.getElementById("para").style.display='block';
      document.getElementById("card").innerHTML="";
    }
    else{
      showgallary(filterarray);
      document.getElementById("para").style.display='none';
    }
  }


})

// My code 
let arr=[]
function addToCart(id,element) {
 arr.push(id)
  localStorage.setItem('userCard',JSON.stringify(arr));
 let item =  JSON.parse(localStorage.getItem('userCard'));
 $("#cart").html(item.length);
//  $(element).attr('disabled', 'disabled');
}
function getCartItems(){
  let product_choosen=[]
 let items = JSON.parse(localStorage.getItem('userCard'));
 for (let i = 0; i < items.length; i++) {
  product_choosen.push(products.find((product)=>product.id==items[i]))
 addCartitemtodom(product_choosen);
 $("#cart").html(product_choosen.length);



 }
}
function addCartitemtodom(items) {
  let total = 0;
  document.getElementById("card").innerText="";
  for(var i=0;i<items.length;i++)
  {
    document.getElementById("card").innerHTML +=
    `<div class="col-md-4 mt-3">
      <div class="card p-3 ps-5 pe-5">
       <h4 class="text-capitalize text-center">${items[i].name}</h4>
       <img src="${items[i].src}" width="100%" height="320px"/>
       <p class="mt-2">${items[i].desc}</p>
       <p class="mt-2">${items[i].price} $</p>
      </div>
     </div>
    `
    total+=items[i].price
  }
  $("#total").html(total);
}

function removeFromCart(id, ele) {
    const index = arr.indexOf(id);

    if (index !== -1) {  //if the item exists in the cart
        arr.splice(index, 1);  // Remove the item from the array
        localStorage.setItem('userCart', JSON.stringify(arr));

        // Optionally update the cart count on the page
        let items = JSON.parse(localStorage.getItem('userCart'));
        $('#cart').html(items.length);
        // updte cart items in the Dom
        getCartItems();
    }
}







