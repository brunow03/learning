class Triangle{
	public Point a, b, c;

	public Triangle(float ax, float ay, float bx, float by, float cx, float cy)
	{
		a = new Point(ax,ay);
		b = new Point(bx,by);
		c = new Point(cx,cy);
		System.out.println("Object \'Triangle\' constructed.");
	}

	public void show()
	{
		if (a != null && b != null && c != null){
			System.out.println("Showing triangle vertices:");
			a.show();
			b.show();
			c.show();
		} else {
			System.out.println("Points were not initialized.");
		}

	}
}