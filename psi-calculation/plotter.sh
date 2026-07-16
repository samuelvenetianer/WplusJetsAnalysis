#!/bin/bash

for file in /cluster/tufts/beaucheminlab/svenet01/WplusJetsAnalysis/psi-calculation/hists/*; do
    echo "Processing $file"
    python simple_plot.py $file
done
echo "plots generated."
echo "creating pdf..."
python pdf_maker.py
