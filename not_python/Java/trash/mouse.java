class Mouse{
	public float x, y;
	public boolean button = false;

	public void clickButton()
	{
		this.button = true;
	}

	public void freeButton()
	{
		this.button = false;
	}

	public void move(float dx, float dy)
	{
		this.x += dx;
		this.y += dy;
	}

	public void move_x(float dx)
	{
		this.x += dx;
	}

	public void move_y(float dy)
	{
		this.y += dy;
	}

	public boolean showState()
	{
		return this.button;
	}
}