const swiper = new Swiper('.swiper-container', {
  loop: true, // Enable looping
  pagination: {
    el: '.swiper-pagination',
    clickable: true,
  },
  navigation: {
    nextEl: '.swiper-button-next',
    prevEl: '.swiper-button-prev',
  },
  autoplay: {
    delay: 3000, // Auto slide every 3 seconds
  },
});