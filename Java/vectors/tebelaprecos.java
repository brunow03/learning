class TabelaPrecos{
	public boolean comDesconto = false;
	public double[] Precos;
	public double[] Descontos;

	public void TabelaPrecos(double[] p, double[] d)
	{
		Precos = new double[p.length];
		Descontos = new double[d.length];

		Precos = p;
		Descontos = d;
	}

	public void aplicaDescontos(int[] descontos)
	{
		for (int i = 0; i < this.Precos.length; i++){
			this.Precos[i] = this.Precos[i]*descontos[i];
		}
		this.comDesconto = true;
	}
}