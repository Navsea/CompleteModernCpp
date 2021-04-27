/* Object oriented programming
- Uses objects as fundamental building blocks of programs (as opposed to algorithms)
- Program is created as a collection of objects
- Every object is an instance of a class
- Classes are related through inheritance, objects are related through containment (one object could contain multiple other objects)
- Simulates interactions of objects in real-life systems
- Decreases the complexity, makes code reusable, extensible and maintainable 

Object model: basic principles for writing object oriented programs
- Abstraction
    - Focusses on important aspects, details are left out, represent a person by just a name and age
    - This allows to represent real-life objects in software, without the associated complexity
    - Represented through class, struct, interface, union or struct
    - User should not be concerned with implementation details, they are abstracted from it

- Encapsulation
    - Next step after abstraction
    - Hides implementation details
    - You can change the internal code, without the client being affected (interface needs to stay the same)
    - implemented through access modifiers in OO languages

- Inheritance
    - Next step after encapsulation
    - Represents a hierarchy of classes
    - The classes are related through a "is-a" relationship aka generalization
    - The relationship is due to same behaviours of classes, such as a <dog> in an <aminal>
    - The behaviour is "inhereted" by the children <dog> from the parent class <animal>
    - Children can reuse implementation of parent, or implement their own
    - Promotes code reusablility

- Composition
    - Signifies relationship between objects
    - Represents a "has a" or "part of" relationship, for example <car> has an <engine>

- Polymorphism
    - Means different forms
    - Represents common behaviour with different implementations
    - Response can be different for each object depending on its class and/or arguments
    - fe car, bicycle, person, ect. can move differently (common = move, difference how they move)
    - implemented through function overloading, templates & virtual functions
    - Used in conjunction with inheritance and composition
*/