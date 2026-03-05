// classe contador

class Contador{
	public int num; //atributo this.numero do contador

	public void incrementa()
	{
		this.num += 1;
	}

	public void decrementa()
	{
		this.num -= 1;
	}

	public void comeca(int n)
	{
		this.num = n;
	}

	public void mostra()
	{
		System.out.println(this.num);
	}
}