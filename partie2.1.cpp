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
    int sij =0;
    if(0<=i && i<= N && 0<=j && j<= M){
        sij = (N+1)*j+i;
    }
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
    if(1<=i && i<= N-1 && 1<=j && j<= M-1){
        return ((j-1)*(N-1)+i-1);
    }
}

//question(16)

vector<int> invnumint(int N , int M, int k){
    
    vector <int> resultat ;
   
    if( 0 <= k && k<= (N-1)*(M-1)-1 ){
       
        for(int i = 1; i<=N; i++){

            bool t_test=false;

            for(int j = 1; j<=M; j++){
           
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
    if(0 <= k && k <= (N-1)*(M-1)-1){
        vector<int> vecteur = invnumint(N ,M, k);
        return numgb(N,M,vecteur[0],vecteur[1]);
    }
}

//question 18

int num_gb_int(int N, int M, int s){
    vector<int> m_vecteur = invnumgb(N ,M, s);
    cout<<m_vecteur[0]<<",\t"<<m_vecteur[1]<<"\n";
    return numint(N,M,m_vecteur[0],m_vecteur[1]);
}


// 2.2 Partie triangulation

//fonction de mallage

 vector<vector<int> > maillageTR(int N, int M){
	int K = 2*N*M;
    vector<vector<int> > TGR ;

     vector<int> t_1 (3);
     vector<int> t_2 (3);

    for(int j=0; j<M; j++){

        for(int i=0; i<N; i++){


            t_1[0] = numgb(N,M,i,j);
            t_1[1] = numgb(N,M,i+1,j);
            t_1[2] = numgb(N,M,i+1,j+1);

            t_2[0] = numgb(N,M,i,j);
            t_2[1] = numgb(N,M,i,j+1);
            t_2[2] = numgb(N,M,i+1,j+1);

            TGR.push_back(t_1);
            TGR.push_back(t_2);
        }

    }


     return TGR;
} 

//question (31):

vector < vector <int> > CalcMatBTt(vector<int> xs, vector<int> ys ){ 

	vector < vector <int> >  matrice;
	
	matrice.push_back(vector <int> (2) );
	matrice.push_back(vector <int> (2) ) ;
	
	matrice[0][0] = xs[1] - xs[0];
	
	matrice[0][1] = xs[2] - xs[0];
	
	matrice[1][0] = ys[1] - ys[0];
	
	matrice[1][1] = ys[2] - ys[0];
	
	
	return matrice;
	
}
// int N;
// int M;

/*
vector <int> extendVec (vector<int> V ){
	
	int I = (N-1)*(M-1);
	int G = (N+1)*(M+1);
	
	vector <int> V_f (G);
	
	for (int i = 0 ; i < G ; i++){
	
	
	
	}
	}
	
*/

//question 2.2.2 (31)



// Partie (44)

// question (d)
int N =6;
int M =6;
vector <int> extendVect(vector <int> v){
    int I = (N-1)*(M-1);
	int G = (N+1)*(M+1);
    vector <int> vv(G);
    int k=1;
    for (int s = 1; s < G; s++)
    {   
        //cout <<k<<"\n";
        int neud_s=num_gb_int(M,N,s);
        if(k <= I)
        {
            cout <<neud_s<<"?=="<<k<<"\n";
            if(neud_s==k){
                vv.push_back(v[k]);
                cout <<v[k]<<"je vais bien cool\t";
            } 
        }  
        k++;  
    }
    
    return vv;
}

// question (e) 
vector<int> intVect(vector <int> vv){
    int I = (N-1)*(M-1);
	int G = (N+1)*(M+1);
    vector <int> v;

    for (int s = 1; s <= G; s++)
    {
        vector <int> neud_s=invnumgb(M,N,s);

        for (int k = 1; k <= I; k++)
        {
            vector <int> neud_k=invnumint(N,M,k);

            if(neud_s[0]==neud_k[0] && neud_s[1]==neud_k[1]){
                v.push_back(vv[k]);
            }
        }
        
    }
    return v;
}

//question 10
vector <vector <double> > matvec(vector <double> Xs, vector <double> Ys){ 
    int N=10, M=8;
    std::vector <std::vector <double> > vv ;
    for (int i = 0 ; i <= N+1 ; i--)
    {
        std::vector<double> v;

        for (int j =0 ; i <=M+1 ; i--)
        {
            v.push_back(0);
        }
        vv.push_back(v);
    }
    cout << "*******************numgb le numero global************************\n" << endl;

    for (int i = 0; i < 10; i++)
    {
        /* code */
    }
    
    
    return vv;
}

vector<vector <double> > DiffTerm ( vector<double> xs , vector<double> ys ){


}



int main() {
    // vector<double> sub = Subdiv(2.0, 10);

    // for (int i = 0; i <= 10; i++) {

    //     cout << sub[i] << "\n" << endl;

    // }

    // int re = numgb(10, 10,5, 4);
    // cout << re << "\n" << endl;
    // cout << "*******************************************\n" << endl;

    // vector<int> result = invnumgb(10, 10, 49);
    // cout << "(" << result[0] << "," << result[1] << ")" << "\n" << endl;

    // cout << "Projet ==>Partie 2.1.2\n" << endl;

    // cout << numint(10, 10, 2, 3) << endl;
    // cout << "\n" << endl;
    // cout << "Trouvons les valeurs de i et j\n" << endl;
    // vector<int> invnumin = invnumint(10, 10, 19);
    // cout << "(" << invnumin[0] << "," << invnumin[1] << ")" << "\n" << endl;
    // cout << "La valeur globale\n" << endl;
    // cout << num_int_gb(10, 10, 19) << endl;
    // cout << "\n" << endl;
    // cout << "Le numero interieur est :  k\n" << endl;
    // cout << num_gb_int(10, 10, 19) << endl;

    // cout << "***************************************************************************\n" << endl;

    // cout << "question 31: calcul de la matrice Bt\n" << endl;
    // vector<int> x(3);
    // vector<int> y(3);
    // x[0] = 1;
    // x[1] = 3;
    // x[2] = 2;
    // y[0] = 3;
    // y[1] = 8;
    // y[2] = 6;

    // vector<vector<int> > Bt = CalcMatBTt(x, y);
    // vector<int> m0 = Bt[0];
    // vector<int> m1 = Bt[1];
    // cout << "La matrice bt est :  \n" << endl;

    // for (int i = 0; i < 2; i++) {

    //     for (int j = 0; j < 2; j++) {

    //         cout << Bt[i][j] << "\t";

    //     }
    //     cout << endl;
    // }


    // cout << "***********************Le maillage****************************** \n" << endl;

    // vector<vector<int> > maillage = maillageTR(4, 4);

    // for (int i = 0; i <= 31; i++) {

    //     for (int j = 0; j <= 2; j++) {

    //         cout << maillage[i][j] << "\t";

    //     }
    //     cout << endl;
    // }
    vector <int> v{2,3,4,12,34,3,5,9,10,25,26,67,9,12,33,2,3,34,9,45,8,19,32,34,99};
    vector <int>  vv = extendVect( v);
    // cout << "************** Vecteur Global ****** \n" << endl;
    for (int i = 0; i < vv.capacity(); i++)
    {
        cout << vv[i]<< "\n";
    }
}






	
