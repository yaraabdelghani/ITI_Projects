let slideIndex = 0;
showSlides();

function showSlides() {
    let slides = document.querySelectorAll(".slides");
    let dots = document.querySelectorAll(".dot");
    
    slides.forEach((slide, index) => {
        slide.style.display = "none";  
    });
    
    slideIndex++;
    if (slideIndex > slides.length) {slideIndex = 1}    

    slides[slideIndex-1].style.display = "block";  
    
    dots.forEach((dot, index) => {
        dot.className = dot.className.replace(" active", "");
    });
    dots[slideIndex-1].className += " active";
    
    setTimeout(showSlides, 3000); // Change image every 3 seconds
}

// Next/previous controls
function plusSlides(n) {
    slideIndex += n;
    showSlides();
}
document.getElementById('i').innerHTML = monzer;
// Thumbnail image controls
function currentSlide(n) {
    slideIndex = n;
    showSlides();
}

// Event listeners for next/prev buttons
document.querySelector('.prev').addEventListener('click', () => plusSlides(-1));
document.querySelector('.next').addEventListener('click', () => plusSlides(1));

fetch('https://fakestoreapi.com/products')
        .then(res => res.json())
        .then(console.log)
                .then(data => {
                const productContainer = document.getElementById('productContainer');
                data.forEach(product => {
                    // Create a card for each product
                    const productCard = document.createElement('div');
                    productCard.classList.add('product-card');
                    // Add product image
                    const productImage = document.createElement('img');
                    productImage.src = product.image;
                    productImage.alt = product.title;
                    productImage.classList.add('product-image');
                    productCard.appendChild(productImage);
                    // Add product details
                    const productDetails = document.createElement('div');
                    productDetails.classList.add('product-details');

                    const productTitle = document.createElement('div');
                    productTitle.classList.add('product-title');
                    productTitle.innerText = product.title;
                    productDetails.appendChild(productTitle);

                    const productDescription = document.createElement('div');
                    productDescription.classList.add('product-description');
                    productDescription.innerText = product.description;
                    productDetails.appendChild(productDescription);

                    const productPrice = document.createElement('div');
                    productPrice.classList.add('product-price');
                    productPrice.innerText = `$${product.price}`;
                    productDetails.appendChild(productPrice);

                    productCard.appendChild(productDetails);
                    productContainer.appendChild(productCard);
                });
            })
            .catch(error => console.error('Error fetching the products:', error));