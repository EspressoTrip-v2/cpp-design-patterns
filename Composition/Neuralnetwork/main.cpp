#include <iostream>
#include <vector>
using namespace std;

// CRTP Template
template<typename Self>
struct someNeurons
{
    template<typename T>
    void connectTo(T &other)
    {
        for (Neuron &from: *static_cast<Self *>(this))
        {

            for (Neuron &to: other)
            {
                from.out.push_back(&other);
                to.in.push_back(&from);
            }
        }
    }
};


struct Neuron : someNeurons<Neuron>
{
    vector<Neuron *> in, out;
    unsigned int id;
    Neuron()
    {
        static int id{1};
        this->id = id++;
    }

    Neuron *begin()
    { return this; }
    Neuron *end()
    { return this + 1; }
    friend ostream &operator<<(ostream &os, const Neuron &obj)
    {
        for (auto n: obj.in)
        {
            os << n->id << "\t-->\t[ " << obj.id << " ]" << endl;
        }
        for (auto i: obj.out)
        {
            os << "[ " << obj.id << " ]\t-->\t" << i->id << endl;
        }
        return os;
    }
};

struct NeuronLayer : someNeurons<NeuronLayer>, vector<Neuron>
{
    explicit NeuronLayer(int count)
    {
        while (count-- > 0)
        {
            this->emplace_back(Neuron{});
        }
    }

    friend ostream &operator<<(ostream &os, const NeuronLayer &obj)
    {
        for (auto &o : obj) cout << o;
        return os;
    }

};

int main()
{
    Neuron n1, n2;
    n1.connectTo(n2);
    cout << n1 << n2;

    NeuronLayer layer1{2}, layer2{3};
//    n1.connectTo(layer1);
//    layer2.connectTo(n2);
//    layer1.connectTo(layer2);


    return 0;
}
