class Foma{
	private float x, y;

	public void forma(float a, float b){
		this.x = a;
		this.y = b;
		System.out.println("Object \'forma\' constructed.");
	}

	public float retorna_x(){
		return this.x;
	}

	public float retorna_y(){
		return this.y;
	}

	public void altera_x(float a){
		this.x = a;
	}

	public void altera_y(float a){
		this.y = a
	}

	public void move(float dx, float dy){
		this.x += dx;
		this.y += dy;
	}
}