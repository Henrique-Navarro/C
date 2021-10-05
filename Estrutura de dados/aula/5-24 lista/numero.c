void lerNumero(lista l){ \\ponteiro para a lista
while(in != -1){
// codigo aqui
}
}

lista soma(lista l1, lista l2){
  int carry = 0;
  lista resposta;
  int temp1, temp2;
  while(l1.size > 0 || l2.size > 0){
    temp1 = l1.size > 0 ? l1.pop() : 0;
    temp2 = l2.size > 0 ? l2.pop() : 0;
    resposta.add((temp1 + temp2 + carry)%10);
    carry = (temp1 + temp2 + carry) / 10;
  }
  if(carry > 0) resposta.add(carry);
}

main(){
  lista l1, l2, resposta;
  lerNumero(l1);
  lerNumero(l2);
  resposta = soma(l1,l2);
  mostrar(resposta);
}