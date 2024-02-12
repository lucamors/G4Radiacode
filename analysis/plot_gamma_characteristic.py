import uproot
import numpy as np
import matplotlib.pyplot as plt
import plotly.express as px

def get_cmap(n, name='viridis_r'):
    '''Returns a function that maps each index in 0, 1, ..., n-1 to a distinct
    RGB color; the keyword argument name must be a standard mpl colormap name.'''
    return plt.cm.get_cmap(name, n)

def main():

    energlist = [10+i*10 for i in range(200)][10::20]

    cmap = get_cmap(len(energlist))

    # Open ROOT file
    for idx,energy in enumerate(energlist[::-1]):

        file = uproot.open(f"chr_{energy}_keV.root")
    
        a = file['ht']['edep'].array()
        print("energy >",energy,"keV")
        a = [np.random.normal(i,0.8*np.sqrt(i),1)[0] for i in a]
        
        # fig = px.histogram(a)
        plt.hist(a,bins=2000,range=(0,2000), histtype="step", color=cmap(idx))
    
    plt.yscale("log")
    plt.xlim(0,2000)
    plt.show()
    

if __name__ == "__main__":
    main()