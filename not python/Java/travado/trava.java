class Trava{

	public String quem;

	public boolean travado;

	public void atrave(String q)
	{
		this.travado = true;
		this.quem = q;
	}

	public void adestrave(String q)
	{
		this.travado = false;
		this.quem = q;
	}

	public void atroca(String q)
	{
		this.travado = !this.travado;
		this.quem = q;
	}

	public boolean estado()
	{
		return travado;
	}
}