class Principal{
	public static void main(String[] args) {
		Fracao a,b,c;
		a = new Fracao(5,3);
		b = new Fracao(2,6);
		System.out.print("Esta é a fração a: ");
		a.mostra();
		System.out.print("Esta é a fração b: ");
		b.mostra();
		c = a.soma(b);
		System.out.print("c de a+b: ");
		c.mostra();
		System.out.print("a+b: ");
		c = a.soma(b);
		c.mostra();

		System.out.print("a >= b: ");
		System.out.println(a.maiorouigual(b));

		System.out.print("a == b: ");
		System.out.println(a.igual(b));

		System.out.print("a != b: ");
		System.out.println(a.diferente(b));

		System.out.print("(int)a: ");
		System.out.println(a.converteint());

		System.out.print("(double)a: ");
		System.out.println(a.convertedbl());

	}
}