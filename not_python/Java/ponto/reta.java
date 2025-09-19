class Line{
	public Point a, b; // agregação

	public Line(float ax, float ay, float bx, float by)
	{
		a = new Point(ax,ay); // chamada dos construtores da classe ponto
		b = new Point(bx,by);
		System.out.println("Object \'Line\' constructed.");
	}

	protected void finalize()
	{
		
	}

	public void show()
	{
		if (a != null && b != null) {
			System.out.println("Showing line endpoints:");
			a.show();
            b.show();
        } else {
			System.out.println("Points are not initialized.");
        }
	}

	public float slope()
	{
		if (a != null && b != null) {
			System.out.println("Slope:");
			if (this.b.x - this.a.x != 0) {
				return (this.b.y - this.a.y) / (this.b.x - this.a.x);
            } else {
				System.out.println("Vertical line, undefined slope.");
				return Float.POSITIVE_INFINITY; // Handle vertical line case
            }
        } else {
			System.out.println("Points are not initialized.");
			return Float.NaN; // Return NaN for undefined slope
        }
	}

	public float linearCoefficient()
	{
		if (a != null) {
			System.out.println("Linear Coefficient:");
			return this.a.y - this.slope() * this.a.x;
        } else {
			System.out.println("Points are not initialized.");
			return Float.NaN;
        }
	}

	public float length()
	{
		if (a != null && b != null) {
			System.out.println("Length:");
			return (float) Math.sqrt(Math.pow(this.b.y - this.a.y, 2) + Math.pow(this.b.x - this.a.x, 2));
        } else {
			System.out.println("Points are not initialized.");
			return Float.NaN;
        }
	}

	public Point intersection(Line a)
	{
		float x, y;
		x = (this.linearCoefficient() - a.linearCoefficient()) / (a.slope() - this.slope());
		y = this.slope() * x + a.linearCoefficient();
		System.out.println("Intersection point created");
		return new Point(x,y);
	}
	/*
	public void turn(float theta, Point p)
	{
		this.
	}

	public float getAngleRad()
	{
		return (Math.atan( (double) this.slope() ));
	}*/
}
