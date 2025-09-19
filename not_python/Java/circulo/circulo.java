// Classe círculo, arquivo circulo.java

class Circulo{
	
	public float raio; // valor default = 0
	
	public float x;
	public float y;

	public void inicializa(float ax, float ay, float ar)
	{
		this.x = ax;
		this.y = ay;
		this.raio = ar;
	}
	
	public void move(float dx, float dy)
	{
		this.x += dx;
		this.y += dy;
	}

	public void mostra()
	{
		System.out.println("(" + this.x + "," + this.y + "," + this.retorna_raio() + ")");
	}

	public void altera_x(float a)
	{
		this.x = a;
	}

	public void altera_y(float b)
	{
		this.y = b;
	}

	public void altera_raio(float a)
	{
		this.raio = a;
	}

	public float retorna_raio()
	{
		return this.raio;
	}

	public void retorna_x()
	{
		return this.x;
	}

	public coid retorna_y()
	{
		return this.y;
	}
}
