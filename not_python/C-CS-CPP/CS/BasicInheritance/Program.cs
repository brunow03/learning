using BasicInheritance;

Console.WriteLine("***** Basic Inheritance *****\n");

Car myCar = new Car(80) {Speed = 50};

Console.WriteLine("My car is going {0} MPH", myCar.Speed);
Console.ReadLine();

// Now make a MiniVan object.
MiniVan myVan = new MiniVan {Speed = 10};
Console.WriteLine("My van is going {0} MPH", myVan.Speed);
Console.ReadLine();