
//declaring and initialising variables

const SliderContainer = document.querySelector(".slider-container");
const ImageSlider = document.querySelectorAll(".slider");
const LengthOfSlides = ImageSlider.length;
const arrowUp = document.querySelector(".arrow-up");
var NumberOfSlide = 0;




//slider autoplay
//autoplay goes to right

var SliderAutoplay;
var repeater = () => 
 {
   SliderAutoplay = setInterval(function()
   {
     ImageSlider.forEach((slider) => {slider.classList.remove("active")});

    //it deletes the class from itself if it has it, otherwise it doesn't do anything

     NumberOfSlide++;
     if(NumberOfSlide > LengthOfSlides - 1)
     {
        NumberOfSlide = 0;
     }

     //it resets the autoplay

     ImageSlider[NumberOfSlide].classList.add("active");

     //adds a class the element after deleting it

   }, 2500);
}
repeater();

//calling the function

//appearing of skins

function AppearWhenScroll() 
{
    var skinsTitle = document.querySelector(".skins-title");
    var TitlePosition = skinsTitle.getBoundingClientRect().top;

    //title's position is the top of it's rectangle

    var PositionOfScreen = window.innerHeight;

    //sceen's position is the window's inner height

    if(TitlePosition < PositionOfScreen)

    {
    skinsTitle.classList.add("appeared");

    //adds a class that is styled in the css, whenever the distance from the top of the skinsTitle to the top of the window is smaller than the window height
   //in other words, when the skinsTitle is in the window height
}
    else
    {
        skinsTitle.classList.remove("appeared");

        //if not, the class is removed
    }
}
function AppearWhenScrollbox()
{
    var skins = document.querySelector(".skins");
    var SkinsPosition = skins.getBoundingClientRect().top;
    var PositionOfScreen = window.innerHeight;

    //the same thing as the title

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

        //adds styling and class whenever the position of skins + 600 is smaller than the window height, meaning whenever the arrows bottom position is the same or smaller than the window's, it appears
    }
    else
    {

        arrowUp.classList.remove("appear-arrow");

        //otherwise it removes the class
    }
    
   
}
window.addEventListener("scroll",AppearWhenScroll);
window.addEventListener("scroll", AppearWhenScrollbox);

//calls the functions

//parallax for skins and slider

let allskins = document.querySelector(".poses");

//selects the element .poses, meaning the picture with skins

window.addEventListener("scroll", function()
{
    let ScrollValue = window.scrollY;

    //the variable gets the window's verticle scroll value, meaning it changes everytime you scroll vertically

    allskins.style.bottom = ScrollValue *0.3  + 'px';

    //moves the element up with every scroll, creating the parallax effect
});

//about us cards on click

const Card = document.querySelectorAll(".cardcontainer");
var Length = Card.length;

//selects every element with this class, something like an array, but not exactly, the only similarity is that the index starts at 0 

Card.forEach(cardcontainer =>
    {
         cardcontainer.addEventListener("click", function()
         {
            Card.forEach(card => card.classList.remove("clicked"));

            //removes the class .clicked from every card with each click

            this.classList.toggle("clicked"); 

            //toggle means that if the card has the class it will remove it, but if it doesn't, it will add it

         });
        
    });
   