/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*********************
 * 2.1  Les neouds Projet CalculScientifique
 * ***/

//Question 9 ecrivons la fonction subdiv

vector <double> Subdiv (double a, int N){
     
    double h = 2*a/N;
     
    vector <double> xi = vector<double>(N+1) ;
   
     for (int i = 0; i<=N ; i++){
         
        xi[i]=-a + i*h;
     }
     
     return xi;
}

int numgb (int N, int M , int i, int j ){
     
     double sij = (N+1)*j+i;
     
     return sij;
}

//Question 13

vector <int> invnumgb(int M, int N, int s ){
     
    vector <int> resultat ;
   
    if( 0 <= s && s<= (N+1)*(M+1)-1 ){
       
        for(int i = 0; i<=N; i++){
            bool t_test=false;
            for(int j = 0; j<=M; j++){
           
                if( numgb(N, M,i,j)==s) {
                   
                    resultat.push_back(i);
                    resultat.push_back(j);
                    t_test=true;
                    break;
               
                }
            }
            if (t_test) break;
        }
    }
    return resultat ;

}

/************
 *  Partie 2.1.2 du projet calcul Scientifique UVSQ
**/

//queston (14)

int numint(int N, int M, int i, int j){
    return ((j-1)*(N-1)+i-1);
}

//question(16)

vector<int> invnumint(int N , int M, int k){
    
    vector <int> resultat ;
   
    if( 1 <= k && k<= (N-1)*(M-1)-1 ){
       
        for(int i = 0; i<=N; i++){

            bool t_test=false;

            for(int j = 0; j<=M; j++){
           
                if( numint(N, M,i,j)==k) {
                   
                    resultat.push_back(i);
                    resultat.push_back(j);
                    t_test=true;
                    break;
               
                }
            }
            if (t_test) break;
        }
    }
    return resultat ;
}

//question 17

int num_int_gb(int N, int M, int k){
    vector<int> vecteur = invnumint(N ,M, k);
    return numgb(N,M,vecteur[0],vecteur[1]);
}

//question 18

int num_gb_int(int N, int M, int s){
    vector<int> vecteur = invnumgb(N ,M, s);
    return numint(N,M,vecteur[0],vecteur[1]);
}

int main()
{
    vector <double> sub = Subdiv(2.0, 10);
   
    for (int i = 0; i<=10; i++){
       
        cout<<sub[i]<<"\n"<<endl;
       
    }

    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n"<<endl;

    vector <int> result = invnumgb(10, 10,23);
    cout<<"("<<result[0]<<","<<result[1]<<")"<<"\n"<<endl;

    cout<<"Projet ==>Partie 2.1.2\n"<<endl;

    cout<<numint(10,10,2,3)<<endl;
    cout<<"\n"<<endl;
    cout<<"Trouvons les valeurs de i et j\n"<<endl;
    vector <int> invnumin = invnumint(10, 10,19);
    cout<<"("<<invnumin[0]<<","<<invnumin[1]<<")"<<"\n"<<endl;
    cout<<"La valeur globale\n"<<endl;
    cout<<num_int_gb(10, 10,19)<<endl;
    cout<<"\n"<<endl;
    cout<<"Le numero intérieur k\n"<<endl;
    cout<<num_gb_int(10, 10,19)<<endl;
}

	
