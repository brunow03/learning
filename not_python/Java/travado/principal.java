class Principal{
	public static void main(String[] args) {
		Trava umatrava;

		umatrava = new Trava();
		umatrava.atrave("ProgramaPrincipal");
		System.out.println(umatrava.estado());
		umatrava.adestrave("ProgramaPrincipal");
		System.out.println(umatrava.estado());
	}
}