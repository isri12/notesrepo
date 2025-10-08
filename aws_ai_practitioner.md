---

# AWS AI Practitioner Study Guide  
## **Domain 1: Fundamentals of AI and ML**  
### **Task Statement 1.1: Explain Basic AI Concepts and Terminologies**

---

## 📘 1.1 Introduction to AI and ML

### 🔹 What is Artificial Intelligence (AI)?
**Definition:**  
Artificial Intelligence (AI) is the ability of machines to perform tasks that normally require human intelligence — such as understanding natural language, recognizing images, solving problems, and making decisions.

**Examples:**  
- Alexa understanding your commands (NLP)  
- Amazon’s product recommendations (ML)  
- Self-driving cars (Computer Vision + Reinforcement Learning)

---

### 🔹 What is Machine Learning (ML)?
**Definition:**  
- Machine Learning (ML) is a subset of AI that enables computers to learn from **data** and make predictions or decisions **without being explicitly programmed**.
- powered by Algorithms that incorporate Intellegance into machines
  
**How ML works (simplified flow):**
1. Collect Data  
2. Prepare (clean) Data  
3. Choose a Model (algorithm)  
4. Train the Model (learn from data)  
5. Evaluate the Model (measure accuracy)  
6. Deploy for **inference** (make predictions)

**Examples:**  
- Predicting customer churn  
- Detecting spam emails  
- Forecasting product demand  
- self driving cars
---

## 🧩 Types of Machine Learning

| Type | Description | Example |
|-------|--------------|----------|
| **Supervised Learning** | Uses labeled data; learns mapping input→output. | Predicting house prices |
| **Unsupervised Learning** | Uses unlabeled data; finds hidden patterns. | Customer segmentation |
| **Reinforcement Learning** | Learns via rewards and penalties. | Training robots, game AI |

### **Supervised Learning**
Model is trained on Labeled data. The data includes both the input and correct output. 
    - Regression
        - Output Label: Continious, Predict a continuous numerical value.  
        - Example: House price Predictor , A number (e.g., 150,000,72∘F)
    - Classification 
         - Output Label: Catagorical, Predict a discrete label or category.
         - Example: Spam detector, A category (e.g., "Cat" or "Dog," "Fraud" or "Not Fraud"), 

Sigmoidal function to predict the probability of binary outcome.
Logistic Regression is a binary classification algorithm commonly used in Machine Learning to predict binary outcomes, such as whether a loan will be defaulted or not. The key idea behind Logistic Regression is to model the probability of an event occurring as a function of input features. The output of this model is transformed using the sigmoidal (also known as logistic) function. The sigmoidal function, often represented as the sigmoid function, has an S-shaped curve that maps any input value to an output value between 0 and 1.


🌸 Classification vs. Regression in the IRIS Dataset  - use with anaconda python. 

1. Classification (The Primary Task)
The most common and intended use of the Iris dataset is a multi-class classification problem.
Goal: To predict which of the three distinct species a flower belongs to.
Target Variable (Output): The flower's species, which is a categorical output.
Iris Setosa
Iris Versicolor
Iris Virginica
Since the output is one of a limited number of categories, it is a classification task. It's often called the "Hello World" of Machine Learning classification problems.

2. Regression (A Secondary/Alternative Task)
While the species prediction is classification, the Iris dataset's features are continuous numerical measurements, which can be used to set up a different task—a regression problem.
Goal: To predict a continuous numerical measurement (like sepal length) based on the other measurements (like petal length, sepal width, etc.).
Target Variable (Output): A continuous numerical value (e.g., predicting the exact sepal length in centimeters).
While you can use the data for regression in an academic setting, the dataset's original and most widely adopted purpose is classification.

 
 ### **Unsupervised Learning** 
Unsupervised Learning is about finding "hidden insights" in a dataset without any prior guidance.

|Sub-Task  |	High-Level Goal	|What it Does |
|-------|--------------|----------|
|Clustering 📦	| Group similar observations together.	| Divides the data into natural groupings (clusters) based on similarity.|
|Dimensionality Reduction 📉|	Simplify the data (compression).	| Reduces the number of features/variables while preserving essential information.|
|Association Rule Mining 🔗	| Find relationships between data elements.	| Discovers rules about items that often occur together (e.g., if a customer buys A, they often buy B).|

### 🤖 **Reinforcement Learning: High-Level Overview**
Reinforcement Learning is about an "agent" learning how to behave in an "environment" to maximize a long-term "reward".
Reinforcement Learning  is a type of Machine Learning algorithm that learns from outcomes to make decisions. In reinforcement learning, an agent interacts with an environment and takes actions to maximize cumulative rewards.

| Component	| Role	| Analogy |
|-------|--------------|----------|
|Agent|	The machine learning program that takes action.	| A student.|
|Environment|	The setting the agent interacts with.	| The school/classroom.|
|Action|	The choices the agent can make.	| Studying, playing, asking questions.|
|Reward/Penalty|	Feedback on the agent's action. |	Getting a good grade (reward) or detention (penalty).|
|Policy|	The learned strategy of what action to take in a given state.	| The student's learned habit/strategy for studying or behaving.|

** ML Process:**
1. load Data  
2. Process Data  
3. Choose a Model (algorithm)  example classfier  
4. Train the Model (learn from data)  
5. Evaluate the Model (measure accuracy)  
6. Deploy for **inference** (make predictions)

---

---

### 🔹 Deep Learning (DL)?
**Definition:**  
Deep Learning (DL) is a **subset of Machine Learning** that uses **artificial neural networks** with many layers (deep) to learn complex patterns from massive datasets.

**Examples:**  
- Image recognition (detecting cats vs. dogs)  
- Speech-to-text (Siri, Alexa)  
- Text generation (ChatGPT)

Deep Learning Algorithms:
- Images ans videos
    - Convolutional Neural Network (CNN)
- Sequntial. TimeSeries and Natural Language Data
    - Transformers
    - Long Short Term Memory (LSTM)
    - Recurrent Neural Networks (RNN)
- Images Text Audio Generation
  - Transformers
  - Diffusion Models
  - Generative Adversarial Networks(GAN)


#### Artifical Neural Network
- Layers
- Neurons
    - A neuron in an Artificial Neural Network is the fundamental building block responsible for performing weighted summation and applying an activation function to input data to produce an output.
- Weights
- Activation Function
- Bias

Hidden layers in neural networks are crucial for character recognition because they enable the network to learn and extract complex features and patterns, such as edges, shapes, and curves, which are essential for recognizing characters.

ANN Train using BackPropagation Algorithm
- Guess and coplare
- Measure the Error
- Adjust the Guess
- update the Weights

 #### Deep Learning Models-sequence Models
- NLP
- Speech Recognition
- Music Generation

#### deep learning network architectures.

1. ** FNN (Feed Forward Neural Network)**
A Feed Forward Neural Network (FNN), also known as a Multi-Layer Perceptron (MLP), is the simplest type of neural network where information moves in only one direction—forward—from the input layer, through one or more hidden layers, and to the output layer, with no loops or cycles.

**Key Concept**: Unidirectional data flow (no memory). Each input is processed independently of previous inputs.
Structure: Consists of fully connected layers of neurons, where the output of a neuron is an input to all neurons in the next layer.
**Primary Uses**: Classification, regression, and function approximation for tabular or simple data where the input order is irrelevant (e.g., email spam detection, stock price forecasting).

2. **CNN (Convolutional Neural Network)**
A CNN is a specialized network for processing data with a grid-like topology (like images, which are 2D pixel grids). It uses a mathematical operation called convolution to efficiently extract spatial and hierarchical features.

**Key Concept**: Uses convolutional layers with shared weights (filters) to learn patterns like edges, textures, and shapes across the entire image. This makes it translation-invariant (it can recognize a feature regardless of where it appears in the image).
**Components**: Alternating layers of Convolution (feature extraction), Pooling (dimensionality reduction), and a final Fully Connected layer (classification).
**Primary Uses**: Image and video processing (e.g., image classification, object detection, face recognition), which is its most common application.

3. **RNN (Recurrent Neural Network)**
An RNN is a network designed to handle sequential data (like text, speech, and time series) by having connections that form loops (recurrency). This allows information from a previous step to be carried forward, giving the network a form of "memory" to process data where the order matters. Recurrent Neural Networks (RNNs) are a type of neural network architecture that includes feedback connections. These feedback connections allow RNNs to process sequential data, such as time series, natural language, speech, and more.

- **Key Concept**: Hidden state (or 'memory') is passed from one step in the sequence to the next, enabling the network to learn patterns and dependencies across time steps. Parameters are shared across all time steps.
Limitations: Simple RNNs struggle with long-term dependencies due to the vanishing gradient problem.
Architectural Types (Input-Output Mappings):

- **One-to-One**: Standard FNN processing. (e.g., Image Classification)

- **One-to-Many**: One input generates a sequence output. (e.g., Image Captioning)

- **Many-to-One**: A sequence input generates a single output. (e.g., Sentiment Analysis)

- **Many-to-Many**: A sequence input generates a sequence output. (e.g., Machine Translation, where input and output sequences have different lengths).
    - Many-to-Many Example: Machine Translation involves translating a sentence or a sequence of text from one language to another, which is essentially a sequence-to-sequence problem. In Many-to-Many RNN architecture, the network takes a sequence of inputs and produces a sequence of outputs. In the context of machine translation, this means it can take a sequence of words or tokens in one language as input and generate a corresponding sequence of words or tokens in another language as output.



4. ** Autoencoders**
An Autoencoder is a network designed for unsupervised learning whose main goal is to learn an efficient, compressed representation (encoding) of the input data. The network is trained to reconstruct its own input.

**Key Concept**: Consists of two symmetrical parts: an Encoder that compresses the input into a lower-dimensional representation (latent space or bottleneck), and a Decoder that attempts to reconstruct the original input from that compressed representation.
**Learning Goal**: Minimize the reconstruction error (the difference between the input and the output). The bottleneck forces the network to learn only the most essential features of the data.
**Primary Uses**: Dimensionality Reduction (data compression) and Anomaly Detection (data that cannot be reconstructed well is likely an anomaly or outlier), and Denoising (reconstructing clean data from corrupted input).

5. **Long Short-Term Memory (LSTM)**
LSTM is a special type of Recurrent Neural Network (RNN) explicitly designed to overcome the vanishing gradient problem of standard RNNs and effectively learn long-term dependencies in sequential data. Long Short-Term Memory (LSTM) Neural Networks are the sequence model of choice when it comes to handling and maintaining relevant information over long sequences, making them particularly well-suited for tasks like language modeling, machine translation, and speech recognition.

**Key Concept**: Instead of a single hidden state, LSTMs use a more complex structure called a memory cell and three types of regulatory gates (Forget, Input, and Output) within their recurrent unit.
**Gates Function**: The Forget Gate decides what information to discard from the cell state. The Input Gate decides what new information to store in the cell state. The Output Gate decides what part of the cell state to output as the hidden state. This control structure allows the information flow to be maintained or cut off over long sequences.
**Primary Uses**: Any sequential task requiring context over long time steps, such as speech recognition, handwriting recognition, and complex natural language processing (NLP).

6. **GAN (Generative Adversarial Networks)**
A GAN is a framework composed of two competing neural networks—a Generator and a Discriminator—that are trained simultaneously in an adversarial (competitive) process.

Key Concept: The training is a "two-player game."

Generator (The Forger): Takes random noise as input and tries to create synthetic data (e.g., an image) that looks real.

Discriminator (The Detective): Receives both real data from the training set and fake data from the Generator, and tries to distinguish between the two (classify the input as Real or Fake).

The Goal: The Generator's goal is to fool the Discriminator, and the Discriminator's goal is to not be fooled. This competition drives the Generator to produce increasingly realistic data until the Discriminator can't tell the difference.

Primary Uses: Generating highly realistic synthetic data, especially images (e.g., deepfakes, realistic artwork, novel material design).

7. **Transformers**
The Transformer is a novel architecture introduced in 2017 that eschewed recurrent and convolutional layers in favor of a mechanism called Self-Attention. It is the foundational architecture for modern Large Language Models (LLMs) like GPT and BERT.

**Key Concept**: The Self-Attention Mechanism allows the model to weigh the importance of all other words/tokens in the input sequence when processing a single word/token. This captures complex, long-range dependencies in the data much more efficiently than RNNs.

**Key Advantage**: Unlike RNNs, which process sequences step-by-step (serially), the Transformer can process the entire sequence in parallel, drastically reducing training time and increasing efficiency.

**Components**: Built from stacked Encoder and Decoder blocks (though many modern variants use only one or the other). Each block contains a Multi-Head Attention layer and a Feed-Forward Network.

**Primary Uses:** State-of-the-art in nearly all sequence tasks, especially Natural Language Processing (NLP) like machine translation, text generation, summarization, and also increasingly in computer vision (Vision Transformers).

---
---

### 🔹 Neural Networks Overview
Neural networks mimic how the human brain processes information.

**Basic Structure:**
- **Input Layer:** Accepts data features (e.g., pixels, words, numbers)  
- **Hidden Layers:** Perform transformations and pattern detection  
- **Output Layer:** Produces the prediction or classification  

**Example:**

Input → [Hidden Layer 1] → [Hidden Layer 2] → Output

---
---
### 🔹 Foundation Models

**Definition:**  
A **foundation model** is a **large, pre-trained model** trained on massive, general-purpose datasets. It can be fine-tuned for many downstream tasks such as text generation, image captioning, or summarization.

**Key Features:**
- Pre-trained on diverse data (text, images, or both)
- General-purpose model that can be adapted to specific applications
- Base for generative AI systems

**Examples:**
- **LLaMA (Meta)**  
- **Claude (Anthropic)**  
- **Gemini (Google DeepMind)**  
- **Amazon Titan (AWS)**  

---
---
### 🔹 Large Language Models (LLMs)

**Definition:**  
LLMs are a type of **foundation model** trained on massive text datasets to understand, generate, and reason about human language.

**Architecture Components:**
- **Input Processing:** Tokenizes text input into smaller chunks (tokens).  
- **Input Embedding:** Converts tokens into numerical vector representations.  
- **Transformer Model:**  
  - **Self-Attention Mechanism:** Lets the model focus on relevant parts of the input text.  
  - **Feed-Forward Network:** Learns relationships between tokens for better contextual understanding.  

**Examples:**  
GPT (OpenAI), Claude (Anthropic), Titan Text (AWS), Gemini (Google).

---

### 🔹 Diffusion Models

**Definition:**  
Diffusion models are **generative models** that create new data (like images or videos) by learning to **add and remove noise** from data.

**Two Main Phases:**
1. **Forward Diffusion:**  
   - Gradually adds noise to an image until it becomes pure noise.  
   - Teaches the model how noise corrupts data.
2. **Reverse Diffusion:**  
   - Starts from random noise and removes noise step by step to **generate a realistic image**.

**Examples:**  
- **Stable Diffusion** (text-to-image)  
- **DALL·E 3**  
- **Midjourney**

---
---
### 🔹 Generative AI (GenAI)

**Definition:**  
Generative AI refers to systems that can **create new content** such as text, images, music, or code, rather than just analyzing data.

**Capabilities:**
- Text → Image (Stable Diffusion, DALL·E)  
- Text → Video (Runway, Pika Labs)  
- Text → Audio (MusicGen, AudioLDM)  
- Multimodal generation: combining text, image, and audio inputs.

---

### 🔹 Multimodal in Generative AI

**Definition:**  
Multimodal AI can process and generate **multiple types of data** (text, image, video, audio).

**Examples:**
- Text → Image (e.g., “Generate a photo of a sunset”)  
- Text → Video (e.g., “Make a 5-second clip of a running dog”)  
- Text + Audio → Generate music or speech  

**Example Models:**  
- Gemini (Google)  
- GPT-4 (OpenAI)  
- Amazon Titan Multimodal  

---

### 🔹 GAN (Generative Adversarial Network)

**Definition:**  
GANs are generative models where **two neural networks compete** to create realistic data.

**Architecture:**
- **Generator:** Creates fake data (e.g., synthetic images).  
- **Discriminator:** Tries to distinguish fake data from real data.  

Through this “game,” the generator improves until its outputs look convincingly real.

**Applications:**  
- Deepfakes  
- Image enhancement  
- Style transfer

---
---
## 📚 Advanced AI Model Types and Terms

| Model / Term | Description | Example Use |
|---------------|-------------|--------------|
| **SVM (Support Vector Machine)** | A classical ML algorithm that finds the best boundary (hyperplane) to separate classes. Works well for small to medium datasets. | Email spam classification |
| **RNN (Recurrent Neural Network)** | Designed for **sequential data** (time-series, speech, or text). It retains memory of previous inputs. | Speech recognition, language modeling |
| **LSTM (Long Short-Term Memory)** | A type of RNN that handles **long-term dependencies** better. | Predicting stock trends, translation |
| **ResNet (Residual Network)** | A deep CNN (Convolutional Neural Network) that uses **skip connections** to train very deep models without vanishing gradients. | Image recognition, object detection |
| **WaveNet** | A deep generative model for **audio waveform synthesis** developed by DeepMind. | Google Assistant voice generation |
| **XGBoost (Extreme Gradient Boosting)** | A high-performance **tree-based ML algorithm** for tabular data. Known for speed and accuracy in competitions. | Credit scoring, recommendation systems |
| **CNN (Convolutional Neural Network)** | Specialized neural network for **image data**, extracts spatial features via filters. | Face recognition, medical imaging |
| **Transformer** | Deep learning architecture that uses **self-attention** for parallel text processing; basis for LLMs. | GPT, BERT, Claude |
| **Autoencoder** | Learns compressed representations of data by encoding and decoding. | Anomaly detection, image compression |
| **Reinforcement Learning (RL)** | Learning through **rewards and penalties** to optimize decision-making. | Robotics, gaming AI |
---
---

## ⚡ Summary Visualization (AI Model Landscape)

AI │ ├── Traditional ML │   ├── Linear / Logistic Regression │   ├── Decision Trees / Random Forest │   ├── SVM │   └── XGBoost │ ├── Deep Learning (Neural Networks) │   ├── CNN (images) │   ├── RNN / LSTM (sequences) │   ├── Transformer (text) │   ├── GAN (generative) │   └── Diffusion Models │ └── Foundation Models ├── LLM (GPT, Claude, Titan) ├── Multimodal Models └── GenAI (Text-to-Image/Video/Audio)

---
---
## 💬 Quick Practice Q&A

1. **Q:** What is the main difference between traditional ML and foundation models?  
   **A:** Traditional ML is task-specific, while foundation models are general-purpose and pre-trained on large datasets.

2. **Q:** How do diffusion models generate images?  
   **A:** By reversing a noise process to reconstruct data from random noise.

3. **Q:** What does the discriminator do in a GAN?  
   **A:** It evaluates generated data and helps the generator improve.

4. **Q:** What makes Transformers efficient for text tasks?  
   **A:** The self-attention mechanism processes all words in parallel.

5. **Q:** Why is ResNet important in deep learning?  
   **A:** It allows very deep networks to train efficiently using skip connections.

6. **Q:** What kind of data does an RNN handle best?  
   **A:** Sequential or time-dependent data such as speech or text.

7. **Q:** What is a multimodal model?  
   **A:** A model that can process multiple data types (e.g., text + image).

8. **Q:** How is XGBoost different from neural networks?  
   **A:** XGBoost is a decision-tree-based algorithm optimized for structured tabular data.

---

✅ **You now covered:**
- Neural networks & deep learning layers  
- Foundation, LLM, and diffusion models  
- GANs and multimodal GenAI  
- Classical and advanced ML algorithms  
- AWS context-ready AI vocabulary

---


## 📚 Key AI Terminologies

| Term | Definition | Example |
|------|-------------|----------|
| **Algorithm** | Set of rules or instructions used for learning. | Linear Regression |
| **Model** | Result of training — used for predictions. | Trained spam filter |
| **Training** | Feeding data to the model to learn patterns. | Learning from sales data |
| **Inference** | Using the trained model to make predictions. | Predicting tomorrow’s sales |
| **Bias** | Systematic error causing unfair results. | Favoring one group in hiring |
| **Fairness** | Ensuring model predictions are unbiased. | Equal loan approvals |
| **Fit** | How well a model represents data. | Underfitting / Overfitting |
| **LLM (Large Language Model)** | Deep models trained on huge text data. | GPT, Claude, Titan |
| **Computer Vision (CV)** | Interpreting visual data. | Object detection |
| **NLP (Natural Language Processing)** | Understanding human language. | Chatbots, sentiment analysis |

---

## ⚙️ Types of Inferencing

| Type | Description | Example |
|------|--------------|----------|
| **Batch Inference** | Large data processed in bulk; not time-sensitive. | Nightly sales report |
| **Real-time Inference** | Instant prediction as data arrives. | Fraud detection |

---

## 🧾 Types of Data in AI Models

| Data Type | Description | Example |
|------------|--------------|----------|
| **Labeled Data** | Includes both input and output labels. | Image labeled "cat" |
| **Unlabeled Data** | No output labels; raw data. | Unsorted tweets |
| **Structured Data** | Organized in rows and columns. | Customer database |
| **Unstructured Data** | Free-form text, audio, or video. | Emails, social posts |
| **Tabular Data** | Spreadsheet-like format. | Sales records |
| **Time-Series Data** | Sequential with timestamps. | Stock prices |
| **Image Data** | Pixel-based visual info. | Photos, X-rays |
| **Text Data** | Sentences or words. | Chat logs |

---

## 🧭 Relationship Summary

| Concept | Subset Of | Example |
|----------|------------|----------|
| **Machine Learning (ML)** | AI | Predictive analytics |
| **Deep Learning (DL)** | ML | Image classification |
| **Neural Networks** | DL | ChatGPT’s architecture |

---

## 🧠 Analogy Table

| Concept | Analogy |
|----------|----------|
| **AI** | The entire field of building smart systems |
| **ML** | The method machines use to learn from data |
| **DL** | The brain-like system for deep pattern learning |

---

## 💡 Practice Questions

### 🧩 Basic Concepts
1. **Q:** What is the goal of AI?  
   **A:** To create systems that perform tasks requiring human intelligence.

2. **Q:** How is ML different from traditional programming?  
   **A:** ML learns patterns from data, while traditional code follows fixed rules.

3. **Q:** Relationship between AI, ML, and DL?  
   **A:** Deep Learning ⊂ Machine Learning ⊂ Artificial Intelligence.

4. **Q:** What is “training” in ML?  
   **A:** The process of feeding data into a model so it learns.

5. **Q:** What is “inference”?  
   **A:** Using a trained model to make predictions on new data.

---

### 🔢 Types of Learning
6. **Q:** Which learning type uses rewards or penalties?  
   **A:** Reinforcement Learning.

7. **Q:** Which type finds patterns in unlabeled data?  
   **A:** Unsupervised Learning.

8. **Q:** Example of supervised learning?  
   **A:** Predicting house prices with labeled data.

---

### 🧠 Deep Learning
9. **Q:** What do hidden layers do in a neural network?  
   **A:** Extract complex patterns from input data.

10. **Q:** Why is deep learning called “deep”?  
    **A:** Because it uses multiple layers between input and output.

---

### 💾 Data and Inference
11. **Q:** What’s the difference between labeled and unlabeled data?  
    **A:** Labeled data has outcomes; unlabeled does not.

12. **Q:** Example of real-time inference?  
    **A:** Fraud detection at payment checkout.

13. **Q:** Batch inference example?  
    **A:** Weekly sales forecasting.

---

### ⚖️ Bias, Fairness, and Fit
14. **Q:** What causes bias in models?  
    **A:** Skewed or unrepresentative data.

15. **Q:** What’s overfitting?  
    **A:** When the model memorizes training data and fails on new data.

16. **Q:** How to promote fairness?  
    **A:** Use diverse, balanced, unbiased datasets.

---

### 🤖 LLM & Modern AI
17. **Q:** What does LLM stand for?  
    **A:** Large Language Model.

18. **Q:** Which AWS service provides LLMs?  
    **A:** Amazon Bedrock (Titan, Claude, Jurassic models).

19. **Q:** What is NLP used for?  
    **A:** Understanding and generating human language.

---

### 🧩 Quick True/False Review
| Statement | True/False |
|------------|-------------|
| Deep Learning = AI | ❌ False |
| Supervised Learning needs labeled data | ✅ True |
| Reinforcement Learning uses labeled data | ❌ False |
| Neural networks only process images | ❌ False |
| Real-time inference is used for fraud detection | ✅ True |

---

## 🧾 Summary Diagram (Concept Hierarchy)

Artificial Intelligence │ ├── Machine Learning │   ├── Supervised Learning │   ├── Unsupervised Learning │   └── Reinforcement Learning │ └── Deep Learning └── Neural Networks

---

## 🌩️ AWS AI-Related Services (Preview)
| Service | Purpose |
|----------|----------|
| **Amazon SageMaker** | Build, train, and deploy ML models |
| **Amazon Bedrock** | Access to LLMs and foundation models |
| **Amazon Rekognition** | Computer Vision and image analysis |
| **Amazon Comprehend** | NLP service for text understanding |
| **Amazon Lex** | Chatbot and voice assistant creation |

---

## 🧩 Quick Recap Checklist
✅ Understand AI vs ML vs DL  
✅ Know types of learning (supervised, unsupervised, reinforcement)  
✅ Recognize key AI terms (bias, fairness, model, inference)  
✅ Understand data types and inference modes  
✅ Learn AWS AI services overview  

---

🧭 **Next Step:**  
Continue to **Task 1.2 – Explain key ML model evaluation concepts (accuracy, precision, recall, confusion matrix, etc.)**

### **Task Statement 1.2: **Explain Basic AI Concepts and Terminologies****

---

