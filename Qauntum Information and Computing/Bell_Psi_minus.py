from qiskit import QuantumCircuit
# Script that implements at random the circuit to generate any 1 of the bell basis

# Create a 1-or-2 qubit circuit object
# Apply gates to qubits (and 2qbit gates)
# How to print circuit
# How to write out state circuit creates

# Create new circuit w/ 2 qubits
qc = QuantumCircuit(2)

# add hadamard gate to qubit 0
qc.h(0)

#Perform a controlled-X gate on qubit 1, controlled by qubit 0
qc.cx(1,0)

qc.x(0)
qc.z(1)

print(qc.draw())
print(qc.draw(reverse_bits=True))

# textbook has LSB at the bottom, but IBM puts it at the top