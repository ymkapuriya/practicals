

/*
const goAhead = function(value){
    value = Math.pow(value, 2)
    console.log(value)
}
*/

const demoObject = () => {
    const status = "passive";

    let user = {         // an object
        name: "John",  // by key "name" store value "John"
        age: 30,      // by key "age" store value 30
        [status] : true,
        contact : {
            email : "email@something.com",
            mobile : "2323232"
        },
        dob : new Date()
    };
    console.log("user", user);

    const detail = JSON.stringify(user)
    console.log("detail", detail)
    const userFromJSON = JSON.parse(detail, function(key, value){
        if (key === 'dob'){
            return new Date(value)
        }
        return value;
    })
    console.log("userFromJSON", userFromJSON)
}



const goAhead = (value) => {

    const status = "passive";

    let user = {         // an object
        name: "John",  // by key "name" store value "John"
        age: 30,      // by key "age" store value 30
        [status] : true,
        name : "R"
    };

    console.log(user.address)

    for (const key in user) {
        if (Object.hasOwnProperty.call(user, key)) {
            const element = user[key];
            console.log(key, element)            
        }
    }

    console.log(user)
}

const notValid = function () {
    console.log("Not a valid input")
}

function main(value, ok, cancel) {
    if (value % 2 == 0) {
        value = ok(value)
        console.log(value)
    } else {
        cancel()
    }
}

function run() {

    //main(number, goAhead, notValid)

    
    let sample = [];
    sample.push('first')
    sample.push('second')
    sample.push('third')
    console.log(sample)
    

    sample.forEach(element => {
        //console.log(element)
    });

    const object = {
        first : "First",
        second : "Second"
    }

    //console.log(object)

    for (const key in object) {
        const element = object[key]
        //console.log(element)
    }

    const newSample = sample.map(function(element, index){
        return element.toUpperCase();
    })
    console.log(newSample)
    
}