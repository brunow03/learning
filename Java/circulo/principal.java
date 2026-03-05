// Classe principal

class Principal{
	public static void main(String[] args) {
		Circulo umcirc; // declaração da variável circulo no metodo main
		umcirc = new Circulo(); // alocação dessa variável
		umcirc.x = 0;
		umcirc.y = 0;
		umcirc.raio = 12;
		umcirc.mostra();
		umcirc.move(10, 10);
		umcirc.mostra();
		umcirc.x = 100;
		umcirc.mostra();
		umcirc.move(-1.0f,-1.5f);
		umcirc.mostra();

	}
}
