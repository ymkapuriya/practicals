
function changeBackground() {
    console.log(":hre")
    const element = document.getElementById('page-container')
    element.style.backgroundColor = "yellow"
    console.log(element)
}

function showError(element, message){
    //const hints = document.getElementsByClassName('hint')
    const parent = element.parentElement;
    const hint = parent.getElementsByClassName('hint')[0];
    hint.innerHTML = message
}

function validateForm() {
    let isValid = true;

    //validate name
    const name = document.getElementById('name');
    const words = name.value.split(" ");
    if(words.length !== 3){
        isValid = false;
        showError(name, "First middle last")
    }

    //address
    //const reAddress = /([A-Za-z0-9])*(,)*\s*/g
    /*
    var reAddress = new RegExp("^([a-z]*[A-Z]*[0-9]*(,)*\s*)g");
    console.log(reAddress)

    const address = document.getElementById('address')
    console.log(address.value)
    console.log(reAddress.test(address.value))
    */

    const email = document.getElementById('email')
    const [address, domain] = email.value.split("@")
    if(!(domain === 'ckpcet.ac.in' || domain === 'ckpcet.com')){
        isValid = false;
        showError(email, "Domain : [ckpcet.ac.in, ckpcet.com]")
    }

    const password = document.getElementById('password')
    const pv = password.value;
    let validPassword = pv.length >= 8
    let re = /[A-Z]/
    validPassword = validPassword && re.test(pv)
    re = /@/
    validPassword = validPassword && re.test(pv)
    if(!validPassword){
        isValid = false;
        showError(password, "Password : Length 8, 1 uppercase, 1 special symbol")
    }
    
    const rePassword = document.getElementById('confirm-password')
    if(password.value !== rePassword.value){
        isValid = false;
        showError(rePassword, "Password should match")
    }

    //return isValid;
    return true;
}