int main(){
    std::cout << "Template specialization" << std::endl;
    Cassetta<int> c1(3);
    Cassetta<char> c2('e');
    Cassetta<double> c3(4.3);
        std::cout << "templates" << std::endl;
        Point p1(2,3);
        Point p2(2,5);
        Point p3 = p1 + p2;
        std::cout << "P3 :" <<  p3 << std::endl;
}