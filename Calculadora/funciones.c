int suma(int a, int b){
    int res;
    res = a+b;
    return res;
}
int resta(int a, int b){
    int res;
    res = a-b;
    return res;
}
int multiplicacion(int a, int b){
    int res;
    res = a*b;
    return res;
}
float division(int a, int b){
    float res;
    res = (float)a/b;
    return res;
}
int factorial(int a){
    int x;
    int respuesta = 1;
    for(x=a; x>0; x--){
        respuesta *= x;
    }
    return respuesta;
}
