class Principal{
	public static void main(String[] args) {
		Matriz2DInt teste;
		teste = new Matriz2DInt(5,10);
		for (int i = 1; i < teste.gett(); i++) {teste.atribuiindlin(i,0);}
		System.out.println();
		System.out.println();
		teste.atribuiindlin(teste.linear(5,5),2);
		System.out.println();
		teste.atribuiindlin(teste.linear(4,2),4);
		System.out.println();
		teste.atribuiindlin(teste.linear(5,5),teste.linear(4,2));
		System.out.println();
	}
}