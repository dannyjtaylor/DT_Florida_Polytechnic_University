from qiskit import QuantumCircuit
# Script that implements at random the circuit to generate any 1 of the bell basis

# Create a 1-or-2 qubit circuit object
# Apply gates to qubits (and 2qbit gates)
# How to print circuit
# How to write out state circuit creates

# Create new circuit w/ 2 qubits
qc = QuantumCircuit(2)

# add hadamard gate to qubit 0
qc.h(1)

#Perform a controlled-X gate on qubit 1, controlled by qubit 0
qc.cx(1, 0)

# Add a Z gate to qubit 0
qc.z(0)


# Return a drawing of the ircuit using MatPlotLib ("mpl")
# These guides are written by using Jupyter notebooks,
# which deplay the output of the last line of each cell.
# If you're running this in a script, use "print(qc.draw())" to
# print a text drawing.

print(qc.draw())
print(qc.draw(reverse_bits=True))

# textbook has LSB at the bottom, but IBM puts it at the top