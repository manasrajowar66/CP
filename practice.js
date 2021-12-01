console.log("hello");

class Student {
  constructor(age, name) {
    this.age = age;
    this.name = name;
  }
  getDeatails() {
    return this.name + "'s roll no age " + this.age;
  }
}

var obj1 = new Student(21, "Manas");

console.log(obj1.getDeatails());
