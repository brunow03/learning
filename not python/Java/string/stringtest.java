class StringTest{
	public static void main(String[] args) {
		 String teste = "Olá meu amigo";

		 System.out.println(teste + " André!");

		 teste += " André";

		 System.out.println(teste);

		 char umChar = teste.charAt(5);

		 System.out.println("André " + umChar + teste.substring(3,13));

		 teste = teste.toUpperCase();

		 for (int i = 0; i < teste.length(); i++) {
		 	System.out.print(teste.charAt(i));
		 }

		System.out.println();
		System.out.println(teste.indexOf("AMIGO"));
		System.out.println(teste.indexOf("biba"));
		System.out.println(teste.lastIndexOf("AMIGO"));
		System.out.println(String.valueOf(3.1415f));
	}
}