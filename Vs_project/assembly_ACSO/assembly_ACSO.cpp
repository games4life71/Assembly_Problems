// assembly_ACSO.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std; 

int cmmdc(int a, int b)
{

    //functie care returneaza cmmdc ul  a 2 numere 
    _asm {
        mov eax, a
        mov ebx, b

        //cat timp a sau b diferit de 0 
         //while(a !=0 && b!=0)
     bucla:
            cmp eax, ebx   //conditiile de stop si iesire din functie 
            je afara 

            //vedem care e mai mare 
            //if ( a>b)

            cmp eax, ebx
            jae da
            //daca a<b -> b=b-a
            sub ebx , eax 
            jmp bucla  

          da:    //daca a>b -> a= a-b;
             sub eax , ebx

            

        jmp bucla

                 afara :
             mov a , eax 
    }
    cout << a;
    return a;
}
int functie(int, int)
{

    _asm {

         


         mov eax , [ebp + 8]
         mov ebx , [ebp+12]
         inc eax 
         inc ebx
         inc ebx
         sub eax , ebx 


    }






}
void bubble(int v[])
{
    int n = sizeof(v) / sizeof(v[0]);
    int i, j;
    

    //cel mai tare cod ever 
    //sortare bable sort 
    _asm {

           mov i , 0 
           mov j , 0 
           mov eax , i 
           //mov edx , j 
          // mov ecx, n
           cmp eax , n  
           jge afara_loop
                mov ecx, n
                sub ecx, eax
                dec ecx 
                mov edx, 0 //j   
                cmp edx, ecx
                jge nu_in_for
                    mov ebx, v[edx*4]//v[j]
                    inc edx
                    mov esi, v[edx*4]//v[j+1]
                    cmp ebx, esi
                    jbe no_if
                    mov edi, ebx
                    mov ebx, esi
                    mov esi, edi
                    no_if:
           nu_in_for:
           afara_loop:






       afara_loop1 : 

               
            
                afara_loop2:
        

















     }





 }
int medie_asm(int v[])
{

    //int siz = sizeof(v) / sizeof(v[0]);
    int sum;
    int medie;
    int siz = sizeof(v) / sizeof(v[0]);

    int  i;
    _asm {
        //suma elementelor dintr un vector
        lea edi, v //plasare in registrul edi adresa de inceput a lui v 
        mov i, 0
        mov sum, 0   //initializare cu 0 fiecare variabila 
        mov medie, 0

        bucla_loop :
        mov ecx, i
            mov edx, siz
            cmp ecx, edx     //conditia de stop si saltul  in exterior daca e indeplinita 
            je afara_loop

            mov ebx, dword ptr[edi + ecx * 4]
            add sum, ebx     //adunarea elementului la suma 

            inc i
            jmp bucla_loop  //intoarcerea in loop 

            afara_loop :

        //calculare medie 

        mov eax, sum
           mov edx, 0
            mov ecx, i
            div ecx
            mov medie, eax
          
         
    }

   // return sum;

    }
int element_max(int v[])
{



    int  ok = true;
    int i;
    int maxim; 
    int count;
    int siz = sizeof(v) / sizeof(v[0]);
         
    _asm {

        mov i , 0
        mov maxim ,-1
        lea edi , v 
            
        bucla:
        mov ecx, i
            mov edx, siz
            cmp ecx, edx
            jae afara_loop

               //comparare element curent cu maxim
                mov ecx , i
                mov edx , maxim 
                mov eax , dword ptr [edi +  4*ecx ]
               cmp eax,edx 
                jg  bigger 
                   //mai mic  
                         inc i 
                         jmp bucla

               bigger :
                mov maxim , eax 
                inc i 
                jmp bucla 
              
    afara_loop :
   mov eax ,maxim
      }







}
int toUpper(char*)
{   //caRactere 20 dE nUmere 

    _asm {
        //returneaz numarul de caracter modificate 

         mov esi , [ebp+8]
        
         mov eax , 0 //counter  
         mov bl ,   byte ptr [esi]


    }



  }
struct persoana {
    int varsta; //4 octeti 
    int inaltime;  // 4 octeti 
    char init; //...  aparent tot 4 octeti  ??? 
    


};
struct triunghi {
    unsigned a;
    unsigned b;
    unsigned c;
};
unsigned radical(unsigned x)
{
    return sqrt(x);
}
unsigned aria(triunghi* t  )
{


    //functie care calculeaza aria unui triunghi folosind formula lui  Heron 
     
    _asm {
        mov edi, [ebp + 8] //pointer la inceputul struct ului 
          //calculam semiperimetru 
          mov eax, 0
          add eax, dword ptr[edi] //1 par - a 
          add eax, dword ptr[edi + 4] //2 - b 
          add eax, dword ptr[edi + 8]//3 - c 

          mov edx, 0
          mov ecx, 2
          div ecx  // in eax se afla semiperimetru 

          // p(p-a)(p-b)(p-c)
          mov ebx , eax // in ebx se afla acum semiperimetru 
          mov ecx, ebx 
          sub ecx, dword ptr [edi]  // ....   p-a 
         
           mul ecx 

           mov ecx , ebx 
           sub ecx , dword ptr [edi+4]
           mul ecx 
           mov ecx , ebx  
           sub ecx , dword ptr [edi + 8]
           mul ecx 

            // apelam sqrt 
            push eax 
            call radical
            add esp  , 4

    }


}
int addNum(int, int)
{


    _asm {

        //functie care aduna 2 numere date ca si parametri 

         mov eax, [ebp +8]
         mov ebx , [ebp +12 ]
         add eax,ebx 
          // in eax se afla rezultatul final 
    }






  }
struct st {
    int a;
    char c;
    char b;
};
int is_prime(int)
{
     //verficare daca un numar este prim 
    _asm {
        mov ecx, dword ptr [ebp + 8] // n ul care trebuie verificat 
        mov esi, 2 //index ul 
    bucla :
        
        mov ebx , dword ptr [ebp+8] // n ul nostru 
        shr ebx,1 //impartim la 2 n -ul 
        cmp esi , ebx 
        jg afara_loop 
            
            
             
            mov eax,ecx 
            mov ebx , esi
            mov edx ,0
            div ebx 
            cmp edx , 0 // comparam restul cu 0 
            jne increment_next
             //am gasit un divizor 
            mov eax ,0
            jmp iesire_gasit
            

            increment_next : 
               inc esi
               jmp bucla


                   afara_loop:
                    mov eax, 1

               iesire_gasit:
    }




}
int prime_sum(int[], int)
{   //cate elem sunt prime 


    _asm {

        mov esi , 0 //suma noastra
        mov edi , [ebp+8] //pointer la vector 
        mov ebx , 0 // contorul 
        bucla : 
        mov ecx ,[ebp + 12]
        cmp ebx , ecx 
        je afara_loop 
         //verificam daca numarul de pe pozitia curenta este prim sau nu 
           mov ecx , dword ptr [edi + 4*ebx ]
            push esi
            push ebx 
            push ecx

            call is_prime
            pop ecx //popcorn
            pop ebx 
            pop esi
            //rezultatul se afla in eax 
            cmp eax, 1 
            jne not_prime
              //il adaugam la suma 
            add esi , dword ptr [edi + 4*ebx ]
            inc ebx
            jmp bucla



        not_prime: 
         inc ebx 
         jmp bucla







    afara_loop : 
           mov eax , esi
        

         
    }

    
}
int medie(int sum, int n)
{

    _asm {

        //functie care calculeaza mediea a n numere 
        mov eax , [ebp+8]
        mov edx,0
        mov ebx , [ebp +12]
        div ebx 
        
    }




}
int reverse_asm(int* v1, int* v2, int n)
{
    //verifica daca vectorii sunt invers pusi 
    _asm {


        mov edi , v1 // pointer la primul vector 
        mov esi , v2  //pointer la al doilea vector 

        mov ecx , 0 //contor --- i 
         bucla_for: 
          mov eax , ecx
          mov ebx , [ebp +16 ]  // n ul 
          cmp eax , ebx     
          je afara_loop 

              //nu sunt egale si interam 
              mov eax , [edi + 4*ecx] //elementu din v1
              //trb sa retin n-1 
              sub ebx , ecx 
              dec ebx 
              mov edx , [esi + 4*ebx ] //elementu din v2
              cmp eax , edx 
              jne not_equal 
                //sunt egale si continuam 
                inc ecx // increment i 
                jmp bucla_for


              afara_loop :
  
             mov eax , 1 
            jmp afara_de_tot


      not_equal:
          mov eax , 0 //fals ca nu sunt egale 
          //nu sunt egale 

    afara_de_tot:

    }





}
struct t1 {
    int x; //4
    short x1; //2
    short x2;




};
struct  test {
    double db;  // 0 --- 8 
     int nr; // 8 --- 12
    char y = 'v';  // 12 ---13
   
}t;
int count_words(char*)
{

    //numara cate cuvinte sunt in vector 
    //separatori , . si  ' '
    //"mama a mers la munte,mare.  "1234"
    _asm {
        mov edi , [ebp +8 ] // incarcam pointer ul in registrul edi 
        mov ecx , 0 //contor
        mov esi , 0 // statutul 0 -- afara din cuvant  -- 1 ---in cuvant 
        mov eax ,0
        bucla: 
         mov bl , byte ptr [edi + ecx * 1 ]
         cmp bl , 0 // comparam cu null 
         je afara_loop 

             //vedem daca in bl este separatot 
             //if (bl == ' ' || bl == ',' || b
             cmp bl , ','
             je gasit_separator 
             cmp bl , '.'
             je gasit_separator
             cmp bl , ' '
             je gasit_separator

             //else if ( state == 0 )
             cmp esi , 0 //daca este in afara cuvantului si nu este spatiu 
             je  else_if
         //daca este in cuvant , incrementam contorul si trecem la urmatorul pas 
              inc ecx 
              jmp bucla

             gasit_separator:
                 mov esi , 0
                  inc ecx           //statutul  s a schimbat in 0 --in afara cuvantului   
                 jmp bucla

                     else_if:
                       //este in afara cuvantului si nu este separator 
                          inc eax  //incrementam numarul de cuvinte gasite 
                          mov esi , 1  //este in cuvant    
                          jmp bucla

             afara_loop :





  

    }




}

int main() {
    char s[] = ",,,,,,,";
    cout<<count_words(s);
}