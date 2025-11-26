class Point{
	public float x, y;

	public Point(float ax, float ay)
	{
		this.x = ax;
		this.y = ay;
		System.out.println("Object \'Point\' constructed.");
	}

	public void move(float dx, float dy)
	{
		this.x += dx;
		this.y += dy;
		System.out.println("Object moved.");
	}

	public void show()
	{
		System.out.println("Printing Object \'Point\':");
		System.out.println("(" + this.x + "," + this.y + ")");
	}

	public float module()
	{
		System.out.println("Vector module:");
		return (float) (Math.sqrt( (double) ( Math.pow(this.x, 2) + Math.pow(this.y, 2) ) ));
	}

	public void unitVector()
	{
		this.x /= (this.module());
		this.y /= (this.module());
		System.out.println("Unit vector created.");
	}
}