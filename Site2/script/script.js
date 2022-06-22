//declaring and initialising variables
const SliderContainer = document.querySelector(".slider-container");
const ButtonRight = document.querySelector(".buttonRight");
const ButtonLeft = document.querySelector(".buttonLeft");
const ImageSlider = document.querySelectorAll(".slider");
const SliderIcons = document.querySelectorAll(".slideicon");
const LengthOfSlides = ImageSlider.length;
const arrowUp = document.querySelector(".arrow-up");
var NumberOfSlide = 0;
//action for the right button
ButtonRight.addEventListener("click", () =>
{
    ImageSlider.forEach((slider) => {slider.classList.remove("active")});
    SliderIcons.forEach((slideicon) => {slideicon.classList.remove("active")});
     NumberOfSlide++;
     if(NumberOfSlide > LengthOfSlides - 1)
     {
        NumberOfSlide = 0;
     }
     ImageSlider[NumberOfSlide].classList.add("active");
     SliderIcons[NumberOfSlide].classList.add("active");

});
ButtonLeft.addEventListener("click", () =>
{
    ImageSlider.forEach((slider) => {slider.classList.remove("active")});
    SliderIcons.forEach((slideicon) => {slideicon.classList.remove("active")});
     NumberOfSlide--;
     if(NumberOfSlide < 0)
     {
        NumberOfSlide = LengthOfSlides - 1;
     }
     ImageSlider[NumberOfSlide].classList.add("active");
     SliderIcons[NumberOfSlide].classList.add("active");

});

//slider autoplay
//autoplay goes to right
var SliderAutoplay;
var repeater = () => 
 {
   SliderAutoplay = setInterval(function()
   {
     ImageSlider.forEach((slider) => {slider.classList.remove("active")});
    SliderIcons.forEach((slideicon) => {slideicon.classList.remove("active")});
     NumberOfSlide++;
     if(NumberOfSlide > LengthOfSlides - 1)
     {
        NumberOfSlide = 0;
     }
     ImageSlider[NumberOfSlide].classList.add("active");
     SliderIcons[NumberOfSlide].classList.add("active");
   }, 2500);
}
repeater();


//appearing of skins

function AppearWhenScroll() 
{
    var skinsTitle = document.querySelector(".skins-title");
    var TitlePosition = skinsTitle.getBoundingClientRect().top;
    var PositionOfScreen = window.innerHeight;
    if(TitlePosition < PositionOfScreen)

    {
    skinsTitle.classList.add("appeared");
    }
    else
    {
        skinsTitle.classList.remove("appeared");
    }
   
}
function AppearWhenScrollbox() 
{
    var skins = document.querySelector(".skins");
    var SkinsPosition = skins.getBoundingClientRect().top;
    var PositionOfScreen = window.innerHeight +200;
    if(SkinsPosition < PositionOfScreen)

    {
        
    skins.classList.add("appeared-box");
    
    }
    else
    {
        skins.classList.remove("appeared-box");
    }
    if(SkinsPosition+600 < PositionOfScreen)
    {
        arrowUp.classList.add("appear-arrow");
        arrowUp.style.color = "rgba(255, 255, 255, 0.53)";
    }
    else
    {

        arrowUp.classList.remove("appear-arrow");
    }
    if(SkinsPosition+1400 < PositionOfScreen)
    {
       
        arrowUp.style.color = "black";
    }
    if(SkinsPosition+2150 < PositionOfScreen)
    {
        arrowUp.style.color = "rgba(255, 255, 255, 0.53)";
    }
   
}
window.addEventListener("scroll",AppearWhenScroll);
window.addEventListener("scroll", AppearWhenScrollbox);

//parallax for skins and slider

let allskins = document.querySelector(".skins");

window.addEventListener("scroll", function()
{
    let value = window.scrollY;
    allskins.style.bottom = value *0.3 + 'px';
});
let slider = document.querySelector(".slider-container");

window.addEventListener("scroll", function()
{
    let value = window.scrollY;
    slider.style.bottom = value*0.11 + 'px';
});
let btn = document.querySelector(".btn-container");

window.addEventListener("scroll", function()
{
    let value = window.scrollY;
    btn.style.bottom = value*0.5 + 'px';
});


//about us card zooming and reading info

const Card = document.querySelectorAll(".cardcontainer");
var Length = Card.length;

Card.forEach(cardcontainer =>
    {
         cardcontainer.addEventListener("click", function(click)
         {
            Card.forEach(card => card.classList.remove("clicked"));
            this.classList.toggle("clicked"); 
         });
    });
   