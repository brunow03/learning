class ContadorCiclico{
	int num = 0;

	public void incrementa()
	{
		this.num = this.num + 1;
	}

	public void decrementa()
	{
		this.num = this.num - 1;
	}

	public void mostra()
	{
		System.out.println(this.num % 60);
	}
}