## 1. Cluster Architecture, Installation & Configuration (25%)

------

# Kubernetes Architecture Study Notes for CKA

Here’s a comprehensive breakdown of Kubernetes components to help you prepare for the Certified Kubernetes Administrator exam:

## Control Plane Components

**API Server (kube-apiserver)**

- The front-end for the Kubernetes control plane and the central management point
- All communication goes through the API server - it’s the only component that talks directly to etcd
- Validates and processes REST requests, then updates corresponding objects in etcd
- Exposes the Kubernetes API (typically on port 6443)
- Horizontally scalable - you can run multiple instances for high availability

**etcd**

- Distributed, consistent key-value store that serves as Kubernetes’ backing store
- Stores all cluster data including configuration, state, and metadata
- Only the API server communicates directly with etcd
- Critical for cluster operation - if etcd fails, the cluster loses its source of truth
- Should be backed up regularly (critical for disaster recovery on the CKA exam)
- Runs on port 2379 (client) and 2380 (peer communication)

**Scheduler (kube-scheduler)**

- Watches for newly created Pods with no assigned node and selects a node for them to run on
- Considers factors like resource requirements, hardware/software constraints, affinity/anti-affinity rules, data locality, and workload deadlines
- Two-phase process: filtering (finds feasible nodes) and scoring (ranks feasible nodes)
- Doesn’t actually place the Pod - it just updates the Pod object with the node assignment

**Controller Manager (kube-controller-manager)**

- Runs multiple controller processes as a single binary
- Controllers include: Node Controller (monitors node health), Replication Controller (maintains correct number of pods), Endpoints Controller (populates endpoint objects), Service Account & Token Controllers (creates default accounts and API access tokens for namespaces)
- Each controller watches the cluster state through the API server and makes changes to move current state toward desired state
- Works on a reconciliation loop pattern

**Cloud Controller Manager (cloud-controller-manager)**

- Embeds cloud-specific control logic (only relevant if running on a cloud provider)
- Allows you to link your cluster into your cloud provider’s API
- Runs controllers like Node Controller (cloud-specific), Route Controller, and Service Controller (for cloud load balancers)

## Node Components

**kubelet**

- Primary node agent that runs on each worker node
- Ensures containers described in PodSpecs are running and healthy
- Communicates with the API server to receive Pod specifications
- Manages Pod lifecycle, reports node and pod status back to control plane
- Doesn’t manage containers not created by Kubernetes
- Mounts volumes, downloads secrets, and runs container health checks

**kube-proxy**

- Network proxy that runs on each node
- Maintains network rules that allow communication to Pods from inside or outside the cluster
- Implements part of the Kubernetes Service concept
- Can use iptables, IPVS, or userspace modes for traffic forwarding
- Handles load balancing for Services across backend Pods

**Container Runtime**

- Software responsible for running containers
- Kubernetes supports runtimes that implement the Container Runtime Interface (CRI)
- Common runtimes: containerd, CRI-O, Docker Engine (via cri-dockerd)
- Pulls images, manages container lifecycle (start, stop, delete)

## Additional Important Concepts for CKA

**Pods**

- Smallest deployable unit in Kubernetes
- Can contain one or more containers that share network and storage
- Each Pod gets a unique IP address

**Worker vs Control Plane Nodes**

- Control plane nodes run the control plane components (API server, scheduler, controller manager, etcd)
- Worker nodes run your application workloads (Pods)
- In small clusters or single-node setups, control plane nodes can also run workloads

**Communication Flow Example**

1. User submits a Deployment via kubectl to API server
1. API server validates and stores it in etcd
1. Controller manager detects the new Deployment and creates ReplicaSet
1. ReplicaSet controller creates Pod objects
1. Scheduler assigns Pods to nodes
1. kubelet on assigned nodes sees the Pods and starts containers via container runtime
1. kube-proxy configures networking rules for the new Pods

**Key Points for the Exam**

- Know where each component runs (control plane vs worker nodes)
- Understand the data flow and which components communicate with each other
- Be familiar with troubleshooting commands like `kubectl logs`, `kubectl describe`, and checking component logs in `/var/log`
- Practice backing up and restoring etcd (common exam task)
- Know how to check component health and status

-------

# Kubernetes Command-Line Tools Comparison

Here’s a clear breakdown of the key Kubernetes tools and their purposes:

## Core Kubernetes Tools

**kubectl**

- **What it is**: Command-line tool for interacting with Kubernetes clusters
- **Purpose**: Allows you to run commands against Kubernetes clusters to deploy applications, inspect resources, view logs, and manage cluster operations
- **Runs on**: Your local machine, bastion host, or any machine configured to communicate with the cluster
- **Common uses**:
  - `kubectl get pods` - list pods
  - `kubectl apply -f deployment.yaml` - create/update resources
  - `kubectl logs <pod-name>` - view container logs
  - `kubectl exec -it <pod-name> -- /bin/bash` - execute commands in containers
  - `kubectl describe node <node-name>` - get detailed info about resources
- **Key point**: This is your main interface for day-to-day cluster management

**kubelet**

- **What it is**: Node agent that runs on every worker node (and control plane nodes)
- **Purpose**: Ensures containers are running in Pods as specified
- **Runs on**: Each node in the cluster as a system service/daemon
- **Key responsibilities**:
  - Registers the node with the API server
  - Watches for Pod assignments to its node
  - Starts/stops containers via the container runtime
  - Reports node and Pod status back to control plane
  - Performs container health checks (liveness/readiness probes)
  - Mounts volumes into Pods
- **Key point**: This is NOT a command you run - it’s a background service running on nodes

**kubeadm**

- **What it is**: Tool for bootstrapping and managing Kubernetes clusters
- **Purpose**: Helps you create, upgrade, and maintain production-ready Kubernetes clusters
- **Runs on**: Nodes where you’re setting up or managing the cluster
- **Common uses**:
  - `kubeadm init` - initialize a control plane node
  - `kubeadm join` - join worker nodes to the cluster
  - `kubeadm upgrade` - upgrade cluster components
  - `kubeadm reset` - tear down a node’s Kubernetes installation
  - `kubeadm token create` - generate join tokens
- **Key point**: Used primarily during cluster setup and maintenance, not for daily operations

## Other Important Kubernetes Tools

**kube-proxy**

- **What it is**: Network proxy running on each node
- **Purpose**: Maintains network rules for Service-to-Pod communication
- **Runs on**: Each node as a DaemonSet or system service
- **Key point**: Like kubelet, this runs in the background - not a command you execute

**kube-apiserver**

- **What it is**: The Kubernetes API server (control plane component)
- **Purpose**: Front-end for the Kubernetes control plane
- **Runs on**: Control plane nodes as a static Pod or system service
- **Key point**: This is the component kubectl talks to

**kube-scheduler**

- **What it is**: Control plane component that assigns Pods to nodes
- **Runs on**: Control plane nodes
- **Key point**: Background service, not a user-facing command

**kube-controller-manager**

- **What it is**: Runs controller processes
- **Runs on**: Control plane nodes
- **Key point**: Background service

## Additional Useful Tools

**crictl**

- Command-line tool for CRI-compatible container runtimes
- Used for troubleshooting containers at the runtime level
- Similar to `docker` commands but works with containerd, CRI-O, etc.
- Examples: `crictl ps`, `crictl logs`, `crictl inspect`

**etcdctl**

- Command-line tool for interacting with etcd
- Used for backing up/restoring etcd, checking cluster health
- Important for CKA exam: `etcdctl snapshot save/restore`

**systemctl**

- Not Kubernetes-specific, but essential for managing kubelet and other services
- `systemctl status kubelet` - check kubelet status
- `systemctl restart kubelet` - restart the kubelet service
- `systemctl enable kubelet` - enable kubelet to start on boot

## Quick Comparison Table

|Tool          |Type              |Where It Runs           |When You Use It                     |
|--------------|------------------|------------------------|------------------------------------|
|**kubectl**   |CLI command       |Your workstation/bastion|Daily cluster management            |
|**kubelet**   |Background service|Every node              |Always running (you don’t invoke it)|
|**kubeadm**   |CLI command       |Cluster nodes           |Cluster setup/upgrade/maintenance   |
|**kube-proxy**|Background service|Every node              |Always running (you don’t invoke it)|
|**crictl**    |CLI command       |Cluster nodes           |Container runtime troubleshooting   |
|**etcdctl**   |CLI command       |Control plane/etcd nodes|etcd backup/restore operations      |

## Common Confusion Points

**kubectl vs kubelet**

- `kubectl` = what you type commands into
- `kubelet` = the agent running on nodes doing the actual work

**kubeadm vs kubectl**

- `kubeadm` = sets up the cluster infrastructure
- `kubectl` = manages workloads and resources in an existing cluster

**When do you use each?**

- Setting up a new cluster? → `kubeadm init`
- Deploying an application? → `kubectl apply`
- Troubleshooting why containers won’t start on a node? → Check `kubelet` logs with `journalctl -u kubelet`
- Backing up cluster state? → `etcdctl snapshot save`

## CKA Exam Tips

- Know the difference between these tools cold - exam questions often require using the right tool
- Practice using `kubeadm` to bootstrap clusters
- Master `kubectl` commands - you’ll use it constantly
- Understand that `kubelet` is a service you manage with `systemctl`, not a command you run directly
- Be comfortable troubleshooting by checking logs: `journalctl -u kubelet` for kubelet issues​​​​​​​​​​​​​​​​




------
This section tests your ability to **build, configure, and manage Kubernetes clusters** using `kubeadm` and core Kubernetes components.

### Manage Role-Based Access Control (RBAC)

RBAC is essential for managing access to cluster resources. Here’s how to create a role and bind it to a service account:

```bash
kubectl create role cm-writer --verb=create --resource=configmaps -n dev
kubectl create rolebinding writer-bind --role=cm-writer --serviceaccount=dev:app-sa -n dev
kubectl auth can-i create configmap --as system:serviceaccount:dev:app-sa -n dev
```

### Prepare Underlying Infrastructure

Before setting up Kubernetes, you must prepare your underlying infrastructure. Here’s how to configure the node and disable swap:

```bash
hostnamectl set-hostname control-plane-node
echo "10.0.0.2 worker-node" >> /etc/hosts
swapoff -a
```

This prepares the system to host Kubernetes components.

### Create and Manage Clusters (kubeadm)

To initialize the Kubernetes control plane and deploy a network plugin, use the following commands:

```bash
kubeadm init --pod-network-cidr=192.168.0.0/16
kubectl apply -f https://raw.githubusercontent.com/projectcalico/calico/v3.28.0/manifests/calico.yaml
```

To join worker nodes:

```bash
kubeadm join <CONTROL_PLANE_IP>:6443 --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH>
```

### Manage Cluster Lifecycle

You’ll need to manage your cluster lifecycle, including upgrades. Here’s how to upgrade the cluster to **v1.33**:

```bash
kubeadm upgrade plan
kubeadm upgrade apply v1.33.1
kubelet --version
```

These commands allow you to upgrade your Kubernetes version to the latest stable release.

### Configure HA Control Plane

High availability (HA) for the control plane is essential for production environments. Here’s how to set up a highly available control plane:

```bash
kubeadm init --control-plane-endpoint "LOADBALANCER_DNS:6443" --upload-certs
```

To add an additional control-plane node:

```bash
kubeadm join LOADBALANCER_DNS:6443 --control-plane --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH> --certificate-key <CERT_KEY>
```

### Helm & Kustomize

Helm is a Kubernetes package manager that simplifies application deployment. Kustomize helps you manage configurations. Here’s how you can deploy **nginx** using Helm and apply custom configurations using Kustomize:

```bash
helm repo add bitnami https://charts.bitnami.com/bitnami
helm install nginx bitnami/nginx
kubectl apply -k ./my-kustomization/
```

### CNI / CSI / CRI

Container Network Interface (CNI), Container Storage Interface (CSI), and Container Runtime Interface (CRI) are crucial for network and storage management. Here’s how to verify the CNI configuration and check for available storage drivers:

```bash
crictl info
ls /etc/cni/net.d/
kubectl get csidrivers
```

These commands help you manage and troubleshoot networking and storage drivers in Kubernetes.

### CRDs & Operators

Custom Resource Definitions (CRDs) and Operators help extend Kubernetes capabilities. To interact with CRDs and manage an operator like **Prometheus**, use the following commands:

```bash
kubectl get crds
kubectl describe crd <customresource>
kubectl apply -f https://github.com/prometheus-operator/prometheus-operator/releases/download/v0.70.0/bundle.yaml
```

### New for v1.33 — In-Place Resize & Debugging

Kubernetes v1.33 introduces **in-place pod resizing**—allowing you to increase resources without restarting the pod. Additionally, debugging has improved with tools like `kubectl debug`:

```bash
kubectl patch pod mypod --subresource=resize --type=merge   -p '{"spec":{"containers":[{"name":"app","resources":{"limits":{"cpu":"1","memory":"512Mi"}}}]}}'
kubectl debug pod/mypod -it --image=busybox --target=app -- sh
```

These features make it easier to manage resources dynamically and debug issues on the fly without downtime.
---------------
 Mumshad Mannambeth Certified Kubernetes Administrator (CKA) with Practice Tests
udemy.com/course/certified-kubernetes-administrator-with-practice-tests/  
https://github.com/kodekloudhub/certified-kubernetes-administrator-course?tab=readme-ov-file 

02-Core-Concepts

01-Core-Concepts-Section-Introduction
02-Cluster-Architecture
03-Docker-vs-ContainerD
04-ETCD-For-Beginners
05-ETCD-in-Kubernetes
06-Kube-API-Server
07-Kube-Controller-Manager
08-Kube-Scheduler
09-Kubelet
10-Kube-Proxy
11-Pods
12-Practice-Test-Introduction
13-Practice-Test-PODs
14-ReplicaSets
15-Practice-Tests-ReplicaSet
16-Deployments
17-Practice-Tests-Deployments
18-Namespaces
19-Practice-Test-Namespaces
20-Services
21-Services-ClusterIP
22-Practice-Test-Services
23-Imperative-Commands-with-kubectl
24-Practice-Test-Imperative-Commands
25-Attachments

---

## **Study Guide & Practice — Cluster Architecture, Installation & Configuration (25%)** ✅

**Overview:** Focus on kubeadm-based cluster installation, control plane components, HA, node prep, lifecycle management, networking (CNI), storage (CSI), CRDs/operators, and debugging tools.

### 🔧 Key Concepts (what to memorize)
- **Control plane components:** `kube-apiserver`, `kube-controller-manager`, `kube-scheduler`, **etcd** (data store).
- **Node components:** `kubelet`, `kube-proxy`, container runtime (containerd / Docker shim).
- **HA pattern:** load-balancer endpoint + multiple control-planes + shared/external etcd.
- **kubeadm basics:** `kubeadm init`, `kubeadm join`, `--control-plane-endpoint`, `--upload-certs` / `--certificate-key` for adding control-plane nodes.

### ⚙️ Essential Commands (cheat-sheet)
```
# Initialize control plane with pod CIDR
kubeadm init --pod-network-cidr=192.168.0.0/16

# Install Calico network plugin
kubectl apply -f https://raw.githubusercontent.com/projectcalico/calico/v3.28.0/manifests/calico.yaml

# Join a worker node
kubeadm join <CONTROL_PLANE_IP>:6443 --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH>

# HA init with upload-certs
kubeadm init --control-plane-endpoint "LOADBALANCER_DNS:6443" --upload-certs

# Add control plane node
kubeadm join LOADBALANCER_DNS:6443 --control-plane --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH> --certificate-key <CERT_KEY>

# Upgrade plan and apply
kubeadm upgrade plan
kubeadm upgrade apply v1.33.1
kubelet --version

# RBAC and testing
kubectl create role cm-writer --verb=create --resource=configmaps -n dev
kubectl create rolebinding writer-bind --role=cm-writer --serviceaccount=dev:app-sa -n dev
kubectl auth can-i create configmap --as system:serviceaccount:dev:app-sa -n dev

# Networking/runtime checks
crictl info
ls /etc/cni/net.d/
kubectl get csidrivers
```

### 🧪 Practice Labs (do these under a time limit)
1. **Single control-plane cluster:** init control-plane, join 2 workers, install Calico, deploy nginx, verify pod network and service.
2. **HA control-plane:** configure a simple load-balancer (HAProxy or MetalLB simulation), add a 2nd control-plane node with `--control-plane`.
3. **Upgrade practice:** drain a worker, upgrade kubelet, uncordon, verify workloads. Run `kubeadm upgrade plan` and simulate the control-plane upgrade.
4. **RBAC lab:** create Role + RoleBinding for a service account and verify with `kubectl auth can-i`.

### 🔎 Debugging & v1.33 features
- Use `kubectl debug` to troubleshoot pods with ephemeral containers.
- In-place resize (v1.33): `kubectl patch pod mypod --subresource=resize -p '{"spec":...}'` to increase resources without restart.
- Use `kubectl logs`, `kubectl describe`, `crictl` and `journalctl -u kubelet` for root-cause analysis.

### ✍️ Exam Tips
- Always prepare nodes (swapoff, hostnames, /etc/hosts updates, container runtime) before `kubeadm init`.
- Practice the exact `kubeadm` flags for HA and `join` operations — exam questions are detail-oriented.
- Timebox practice labs to 15–20 minutes each and practice diagnosing failures quickly.

---

*Study guide created from course notes and practice labs — let me know if you want me to expand any lab into step-by-step commands or add screenshots.*