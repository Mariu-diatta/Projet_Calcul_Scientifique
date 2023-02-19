/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>

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
    vector<int> vecteur;
    if(0 <= k && k <= (N-1)*(M-1)-1){
        vecteur = invnumint(N ,M, k);
    }
    return numgb(N,M,vecteur[0],vecteur[1]);
}

//question 18

int num_gb_int(int N, int M, int s){
    vector<int> m_vecteur = invnumgb(N ,M, s);
    return numint(N,M,m_vecteur[0],m_vecteur[1]);
}


// 2.2 Partie triangulation

//fonction de mallage

 vector<vector<int> > maillageTR(int N, int M){

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

	vector < vector <int> >  mat;
	
	mat.push_back(vector <int> (2) );

	mat.push_back(vector <int> (2) ) ;
	
	mat[0][0] = xs[1] - xs[0];
	
	mat[0][1] = xs[2] - xs[0];
	
	mat[1][0] = ys[1] - ys[0];
	
	mat[1][1] = ys[2] - ys[0];
	
	
	return mat;
	
}

// //question 37 :

//  // cette fonction permet de calculer la matrice inverse


//  vector <vector <double> > BT_inv ( vector <vector <double> >   M,double determinant){

//      vector < vector <double> >  matri;

//      matri.push_back(vector <double> (2) );
//      matri.push_back(vector <double> (2) ) ;
//      matri[0][0] = (1/determinant)*M[1][1];

//      matri[0][1] = -(1/determinant)*M[0][1];

//      matri[1][0] = -(1/determinant)*M[1][0];

//      matri[1][1] = (1/determinant)*M[0][0] ;

//      return   matri;


//  }

//  //Transpose de la matrice inverse de BT
// vector <vector <double> > BT_inv_t ( vector <vector <double> >   M){

//     vector < vector <double> >  matri;

//     matri.push_back(vector <double> (2) );
//     matri.push_back(vector <double> (2) ) ;
//     matri[0][0] = M[1][1];

//     matri[1][0] = -M[0][1];

//     matri[0][1] = -M[1][0];

//     matri[1][1] = M[0][0] ;

//     return   matri;


// }
// //calcul du produit de deux matrices inverse de BT et BT transpose

// vector<vector<double>> produit_matrice(vector<vector<double>> A, vector<vector<double>> B,vector<vector<double>> &P ){

//     P = vector<vector<double>>(2);
//     vector<double>p(2) ;
//     for (int i=0; i<2; i++){

//         for (int j=0; j<2; j++){
//             double s =0 ;
//             for (int k=0; k<2; k++){

//                 s = s + A[i][k]*B[k][j]; }

//             p[j]=s;
//         }
//         P[i] = p;

//     }
//     return P;

// }

// //////Produit de vecteur-matrice
// vector<double> produit_vecteur_matrice(vector<vector<double>>m,  vector<double> v ,vector<double> &resultat)
// {
//     resultat = vector<double>(v.size());
//     double s ;

//     for(int j=0; j<2; j++)
//     {
//         s = 0 ;
//         for(int i=0;i<2;i++)
//             s += m[j][i]*v[i] ;
//         resultat[j] = s ;
//     }
//     return resultat;
// }

// //Produit matrice vecteurs
// vector<double> produit_matrice_vecteur(vector<vector<double>>m,  vector<double> v ,vector<double> &resultat)
// {
//     resultat = vector<double>(v.size());
//     double s ;

//     for(int j=0; j<2; j++)
//     {
//         s = 0 ;
//         for(int i=0;i<2;i++) s += m[i][j]*v[i] ;
//         resultat[j] = s ;
//     }
//     return resultat;
// }


// vector<vector <double> > DiffTerm ( vector<double> xs , vector<double> ys ) {

//    vector <vector<double>> matrice;

//     vector<double> ligne(3);

//    double det = (xs[1]-xs[0])*(ys[2]-ys[0]) - (xs[2]-xs[0])*(ys[1]-ys[0]);

//     vector<vector<double>> B = CalcMatBTt(xs,ys);

//     vector<vector<double>> B1 = BT_inv(B, det);
//     vector<vector<double>> B2 = BT_inv_t(B1);

//     // Les gradientlamdai pour 0<=i<=2
//     vector<double> gradient_0 = {-1, -1};
//     vector<double> gradient_1 = {1, 0};
//     vector<double> gradient_2 = {0, 1};
//     vector<vector<double> > gradient = {gradient_0, gradient_1, gradient_2};
//     vector<vector<double> > grad;
//     //cette boucle calcul les gradient lamda k transpose multiplie par les lamda j
//     //vector< vector<double> > p = produit_matrice(B1,B2);
//     vector<double> B3;
//     vector<double> B33;

//     for (int k = 0; k < 3; ++k) {

//         for (int j = 0; j < 3; ++j) {

//             vector<double> B4 =   produit_matrice_vecteur(B1,gradient[j], B3);
//             vector<double> B5 =   produit_matrice_vecteur(B2,B4, B33);

//          ligne[j]= inner_product( gradient[k].begin(),gradient[k].end(),B5.begin(), 0   );

//         }
//         matrice.push_back(ligne);
//     }

//       return matrice;

// }
// int N;
// int M;
// vector<vector <float> > ConvectTerm ( vector<double> xs , vector<double> ys ){
//     double det = (xs[1]-xs[0])*(ys[2]-ys[0]) - (xs[2]-xs[0])*(ys[1]-ys[0]);
//     vector<vector <float> > matrice ;
//     vector<float> ligne(3);
//     //lamda va contenir les integrales des lamdas pour j= 0,1 et 2
//     vector <float> lamda { -1/6, 1/6, 1/6 };

//     //lamda_k va contenir les integrales partiel de x des lamdas pour k= 0,1 et 2

//     vector <float> lamda_k {-1, 1, 0};

//     for (int k = 0; k <3 ; ++k) {

//         for (int j = 0; j < 3; ++j) {

//             ligne[j]= det*lamda_k[k]*lamda[j];

//         }
//         matrice.push_back(ligne);
//     }
//     return matrice;

// }

vector<vector <int> > ReacTerm ( vector<int> xs , vector<int> ys ){
    int det = abs((xs[1] - xs[0])*(ys[2] - ys[0]) -(xs[2] - xs[0])*(ys[1] - ys[0]));
    vector<vector <int> > matrice ;
    vector <int> M0{ det/24,det/48, det/48 };
    vector <int> M1{ det/48,det/24, det/48 };
    vector <int> M2{ det/48,det/48 ,det/24 };
    matrice.push_back(M0);
    matrice.push_back(M1);
    matrice.push_back(M2);
    return matrice;
}


// Partie (44)

// question (d)

vector <int> extendVect(vector <int> V, int N=6, int M=6){

    int I = V.size();
	int G = (N+1)*(M+1);
    vector <int> W(G);
    int k=0;

    for (int s = 0; s < G; s++)
    {   
        int neud_s=num_gb_int(M,N,s);
        if(k < I)
        {
            if(neud_s==k){
                W[s]=V[k];
            }else
            {
                W[s]=0;
            } 
        }  

        k++;  
    }
    
    return W;
}

// question (e) 
vector<int> intVect(vector <int> W, int N=6, int M=6){

    int I = (N-1)*(M-1);
	int G = W.size();
    vector <int> V(I);
    int k=0;

    for (int s = 0; s < G; s++)
    {
        if(k < I)
        {
           int neud_s=num_gb_int(M,N,s);
           if(neud_s==k){
                V[k]=W[s];
            }
        }

        k++;  
    }
    return V;
}

//question 10
 vector <vector <int>> calcul_BT(int t, int N, int M,  vector <int> xs, vector <int> ys){

   vector <int>  t_trg;
   t_trg=(maillageTR(N,M))[t];
   vector <int> V1= invnumgb(M,N,t_trg[0]);
   vector <int> V2= invnumgb(M,N,t_trg[1]);
   vector <int> V3= invnumgb(M,N,t_trg[2]);

   // la fonction jacobien  
   for (int i = 0; i <=2; i++)
   {
        xs.push_back(V1[0]);
        xs.push_back(V2[0]);
        xs.push_back(V3[0]);
   }

   for (int i = 0; i <=2; i++)
   {
        ys.push_back(V1[1]);
        ys.push_back(V2[1]);
        ys.push_back(V3[1]);
   }
   
   vector <vector <int>> matrix_g= CalcMatBTt(xs,ys);

   return matrix_g;
}

int TRG(int t, int i, int N=6, int M=6){

    int n_trg=0;
    vector<vector<int>> liste_trg;
    vector<int> t_trg;
    int glb=0;

    if(i <= 2)
    {
        liste_trg = maillageTR(N, M);
        t_trg = liste_trg[t];
        glb=t_trg [i];  
    }
    return glb;
}

vector <int>  matVec(vector <int> v, int K, int N=6, int M=6){

    std::vector <int>  WW((N+1)*(M+1)) ;

    std::vector <std::vector <int> > B;

    vector<int> W;
    
    vector <int> xs;

    vector <int> ys;

    int s=0;


    for (int t= 0 ; t <= K-1 ; t++){

        B=calcul_BT(t,N,M,xs,ys);

        for (int i = 0; i <= 2; i++)
        { 
            s=TRG(t,i,N,M);

            int res=0;

            for (int j = 0; j <= 2 ; i++)
            {
              int r = TRG(t,j, N, M)  /* code */;

              int PROD2=ReacTerm (xs, ys)[i][j];
              
              res=res + (extendVect(v,N,M)[r])*PROD2;

              WW[s]=WW[s]+res;
            }
        }
    }

    W=intVect(WW);

    return W;
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
    // cout << "question 31: calcul de la matrice Bt\n" << endl;
    // vector<double> x(3);
    // vector<double> y(3);
    // x[0] = 1;
    // x[1] = 3;
    // x[2] = 2;
    // y[0] = 3;
    // y[1] = 8;
    // y[2] = 6;

    // // vector<vector<int> > Bt = CalcMatBTt(x, y);
    // // vector<int> m0 = Bt[0];
    // // vector<int> m1 = Bt[1];
    // // cout << "La matrice bt est :  \n" << endl;
    // vector<vector<double> > Bt = CalcMatBTt(x, y);
    // vector<double> m0 = Bt[0];
    // vector<double> m1 = Bt[1];
    // cout << "La matrice bt est :  \n" << endl;

    // // for (int i = 0; i < 2; i++) {

    // //     for (int j = 0; j < 2; j++) {

    // //         cout << Bt[i][j] << "\t";
    //         cout << Bt[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << "La matrice bt inv est :  \n" << endl;
    // double d = abs((x[1] - x[0])*(y[2] - y[0]) -(x[2] - x[0])*(y[1] - y[0]));
    // vector<vector<double>> Bt_I = BT_inv(CalcMatBTt(x, y), d);

    // for (int i = 0; i < 2; i++) {

    //     for (int j = 0; j < 2; j++) {

    //         cout << Bt_I[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << "La matrice bt inv_t est :  \n" << endl;
    // vector<vector<double>> Bt_I_INV = BT_inv_t(Bt_I);
    // for (int i = 0; i < 2; i++) {

    //     for (int j = 0; j < 2; j++) {

    //         cout << Bt_I_INV[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    // cout << "LE produit de matrice vecteur :  \n" << endl;
    // vector<double> bb{2,3};
    // vector <double> resultat;
    // produit_matrice_vecteur(Bt_I,bb,resultat);
    // for (int i = 0; i < 2; i++) {

    //     cout <<  resultat[i]<< "\t";

    //     cout << endl;
    // }

    // cout << "***********************Produit matriciel****************************** \n" << endl;
    // vector<double> b11{1,4};
    // vector<double> b12{2,2};
    // vector<vector<double>> b1{b11, b12  };
    // vector<double> a11{1,2};
    // vector<double> a12{2,1};
    // vector<vector<double>> a1{a11, a12 };
    // vector<vector<double>> P;
    // produit_matrice(a1, b1, P);

    // for (int i = 0; i < 2; i++) {

    //     for (int j = 0; j <2; j++) {

    // //     }
    // //     cout << endl;
    // // }
    //         cout << P[i][j] << "\t";
    //     }
    //     cout << endl;
    // }


    // // cout << "***********************Le maillage****************************** \n" << endl;

    // // vector<vector<int> > maillage = maillageTR(4, 4);

    // // for (int i = 0; i <= 31; i++) {

    // //     for (int j = 0; j <= 2; j++) {

    // //         cout << maillage[i][j] << "\t";

    // //     }
    // //     cout << endl;
    // // }
    vector <int> v{2,3,4,12,34,3,5,9,10,25,26,67,9,12,33,2,3,34,9,45,8,19,32,34,99};
    vector <int>  vv = extendVect( v);
     vector <int>  v1 = intVect( vv);
    // cout << "************** Vecteur Global ****** \n" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i]<< "\n";
    }
    // for (int i = 0; i < vv.size(); i++)
    // {
    //     cout << vv[i]<< "\n";
    // }



    // cout << "***********************Fonction DiffTerm******************** \n" << endl;

    // vector< vector<double>> diff = DiffTerm(x,y);
    // for (int i = 0; i < 3; i++) {

    //     for (int j = 0; j < 3; j++) {

    //         cout << diff[i][j] << "\t";

    //     }
    //     cout << endl;
    // }

    // cout << "***********************Fonction ReacTerm******************** \n" << endl;

    // vector< vector<double>> dif = ReacTerm(x,y);
    // for (int i = 0; i < 3; i++) {

    //     for (int j = 0; j < 3; j++) {

    //         cout << dif[i][j] << "\t";

    //     }
    //     cout << endl;
    // }


    // cout << "***********************Fonction ConvectTerm******************** \n" << endl;

    // vector< vector<float>> convect = ConvectTerm(x,y);
    // for (int i = 0; i < 3; i++) {

    //     for (int j = 0; j < 3; j++) {

    //         cout << convect[i][j] << "\t";

    //     }
    //     cout << endl;
    // }

}






	
