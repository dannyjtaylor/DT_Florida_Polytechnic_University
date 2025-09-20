from qiskit import QuantumCircuit
from qiskit.quantum_info import Statevector
from numpy.random import randint
qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)

print(qc.draw())
print(qc.draw(reverse_bits=True))




# how to print a state vector, "qc" has our quantum circuit data
sv = Statevector.from_instruction(qc)
print(str(sv[0]) + "|00>")
print(str(sv[1]) + "|01>")
print(str(sv[2]) + "|10>")
print(str(sv[3]) + "|11>")

# remember 1/sqrt(2) = 0.7071067811865475

# use randint function

# how you can generate random numbers
num = random.randint(0,4)
# num will be 0, 1, 2, or 3



if (num == 1):
    # generate Bell Phi plus
    # Create new circuit w/ 2 qubits
    qc1 = QuantumCircuit(2)

    # add hadamard gate to qubit 1, (not qubit 0)
    qc1.h(1)

    #Perform a controlled-X gate on qubit 0, controlled by qubit 1
    qc1.cx(1,0)
    print(qc.draw(reverse_bits=True))

elif (num == 2):
    # generate Bell Phi minus
    qc2 = QuantumCircuit(2)

# add hadamard gate to qubit 0
    qc2.h(0)

#Perform a controlled-X gate on qubit 1, controlled by qubit 0
    qc2.cx(1,0)

    qc2.x(0)
    qc2.z(1)

    print(qc2.draw(reverse_bits=True))

elif (num == 3):
    # generate Bell Psi plus
    # Create new circuit w/ 2 qubits
    qc3 = QuantumCircuit(2)

    # add hadamard gate to qubit 0
    qc3.h(1)

    #Perform a controlled-X gate on qubit 1, controlled by qubit 0
    qc3.cx(1,0)

    # qc.x(1)

    print(qc3.draw(reverse_bits=True))


else:
    # generate Bell Psi minus
    # Create new circuit w/ 2 qubits
    qc4 = QuantumCircuit(2)
    qc4.h(0)
    qc4.cx(1,0)
    qc4.x(0)
    qc4.z(1)
    print(qc4.draw(reverse_bits=True))

# generate one of hte four bell circuits, print out circuit and states